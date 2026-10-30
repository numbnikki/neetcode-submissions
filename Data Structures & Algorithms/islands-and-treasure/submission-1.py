class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        visited = set()
        que = deque()
        ROWS = len(grid)
        COLS = len(grid[0])

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    que.append([i, j])
                    visited.add((i, j))
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        # Do it in batches
        distance = 0
        while que:
            batchLen = len(que)
            for i in range(batchLen):
                x, y = que.popleft()
                grid[x][y] = distance

                for dir in directions:
                    xx, yy = x + dir[0], y + dir[1]
                    if (
                        (xx < 0 or xx >= ROWS)
                        or (yy < 0 or yy >= COLS)
                        or ((xx, yy) in visited)
                        or grid[xx][yy] == -1
                    ):
                        continue
                    que.append([xx, yy])
                    visited.add((xx, yy))
            distance += 1
