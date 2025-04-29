from typing import List
from heapq import heappush, heappop

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        n, m = len(heightMap), len(heightMap[0])
        min_heap = []
        for row in range(n):
            for col in range(m):
                if row in [0, n-1] or col in [0, m-1]:
                    heappush(min_heap, (heightMap[row][col], row, col))
                    heightMap[row][col] = -1

        res = 0
        max_height = -1
        while min_heap:
            height, row, col = heappop(min_heap)
            max_height = max(max_height, height)
            res += max_height - height

            directions = [[row+1, col], [row-1, col], [row, col+1], [row, col-1]]
            for Drow, Dcol in directions:
                if (Drow < 0 or Dcol < 0 or Drow == n or Dcol == m or heightMap[Drow][Dcol] == -1):
                    continue
                heappush(min_heap, (heightMap[Drow][Dcol], Drow, Dcol))
                heightMap[Drow][Dcol] = -1
        return res

def main():
    import sys
    heightMap = [list(map(int, line.strip().split())) for line in sys.stdin if line.strip()]
    if heightMap:
        sol = Solution()
        print(sol.trapRainWater(heightMap))

if __name__ == "__main__":
    main()