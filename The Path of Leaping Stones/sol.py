from typing import List

def ThePathofLeapingStones(stones: List[int]) -> bool:
    goal = len(stones) - 1
    for i in reversed(range(len(stones) - 1)):
        if stones[i] + i >= goal:
            goal = i
    return goal == 0

if __name__ == "__main__":
    stones = list(map(int, input().split()))
    print(ThePathofLeapingStones(stones))
