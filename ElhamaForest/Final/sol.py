# using segment tree with lazy propagation + primes theory

class SegmentTree:
    def __init__(self, size):
        self.N = size
        self.tree = [0] * (4 * size)
        self.lazy = [None] * (4 * size)

    def push(self, node, l, r):
        if self.lazy[node] is not None:
            val = self.lazy[node]
            self.tree[node] = (r - l + 1) * val
            if l != r:
                self.lazy[node * 2] = val
                self.lazy[node * 2 + 1] = val
            self.lazy[node] = None

    def build(self, node, l, r, arr):
        if l == r:
            self.tree[node] = arr[l]
            return
        m = (l + r) // 2
        self.build(node * 2, l, m, arr)
        self.build(node * 2 + 1, m + 1, r, arr)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

    def update(self, node, l, r, ql, qr, val):
        self.push(node, l, r)
        if r < ql or l > qr:
            return
        if ql <= l and r <= qr:
            self.lazy[node] = val
            self.push(node, l, r)
            return
        m = (l + r) // 2
        self.update(node * 2, l, m, ql, qr, val)
        self.update(node * 2 + 1, m + 1, r, ql, qr, val)
        self.tree[node] = self.tree[node * 2] + self.tree[node * 2 + 1]

    def query(self, node, l, r, ql, qr):
        self.push(node, l, r)
        if r < ql or l > qr:
            return 0
        if ql <= l and r <= qr:
            return self.tree[node]
        m = (l + r) // 2
        return self.query(node * 2, l, m, ql, qr) + self.query(node * 2 + 1, m + 1, r, ql, qr)



def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    # Check if n is not of the form 6k ± 1
    if n % 6 != 1 and n % 6 != 5:
        return False
    # Fermat's test

    if pow(2, n - 1, n) != 1:
        return False
    
    # now we do the basic algorithm that checks if a number is prime 
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True




n = int(input())
a = list(map(int, input().split()))

a = [0] + a  # 1-indexed

tree = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    u, v = map(int, input().split())
    tree[u].append(v)
    tree[v].append(u)

discover = [0] * (n + 1)
begin = [0] * (n + 1)
end = [0] * (n + 1)
flat = [0] * (n + 1)

time = 1
def dfs(u, parent):
    global time
    begin[u] = time
    discover[time] = u
    flat[time] = a[u]
    time += 1
    for v in tree[u]:
        if v != parent:
            dfs(v, u)
    end[u] = time - 1

dfs(1, -1)

# print(discover)
# print(begin)
# print(end)

st = SegmentTree(n + 1)
st.build(1, 1, n, flat)

q = int(input())
for _ in range(q):
    parts = input().split()
    if parts[0] == '1':
        u, val = int(parts[1]), int(parts[2])
        if begin[u] < end[u]:  # u has children
            st.update(1, 1, n, begin[u] + 1, end[u], val)

    else:
        u = int(parts[1])
        total = st.query(1, 1, n, begin[u], end[u])
        #print(total)
        print("YES" if is_prime(total) else "NO")
