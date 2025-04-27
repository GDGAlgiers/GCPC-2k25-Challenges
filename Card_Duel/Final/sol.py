
MAX = 10**5 + 1
next_val = [1] * MAX  

def twist():
    for i in range(2, MAX):
        for j in range(i * 2, MAX, i):
            next_val[j] = i

def solve():
    t = int(input())
    for _ in range(t):
        n = int(input())
        A = list(map(int, input().split()))[:n]
        B = list(map(int, input().split()))[:n]

        op_cpt = 0
        for i in range(n):
            while A[i] != B[i]:
                op_cpt += 1
                if A[i] < B[i]:
                    A[i], B[i] = B[i], A[i]
                A[i] = next_val[A[i]]
        print(op_cpt)

if __name__ == "__main__":
    twist()
    solve()
