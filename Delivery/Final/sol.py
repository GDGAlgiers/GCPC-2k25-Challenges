from itertools import accumulate

def main():
    import sys
    input = sys.stdin.readline

    n = int(input())
    a = list(map(int, input().split()))

    prefix_sum = [0] + list(accumulate(a))

    q = int(input())
    result = []
    for _ in range(q):
        x, y, m = map(int, input().split())
        manual_time = prefix_sum[n] + x
        auto_time = prefix_sum[m] + y
        result.append(str(min(manual_time, auto_time)))

    print("\n".join(result))

if __name__ == "__main__":
    main()
