import sys

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def search(x, y, cnt):
    if(x == haveToVisit[m - 1][0] and y == haveToVisit[m - 1][1] and cnt == m - 2):
        global casesCount
        casesCount += 1
        return
    if x == haveToVisit[cnt + 1][0] and y == haveToVisit[cnt + 1][1]:
        cnt += 1
    
    visited[x - 1][y - 1] = 1

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if (nx >= 1 and nx <= n) and (ny >= 1 and ny <= n) and mat[nx - 1][ny - 1] == 0 and visited[nx - 1][ny - 1] == 0:
            search(nx, ny, cnt)
    
    visited[x - 1][y - 1] = 0

    
input = sys.stdin.readline
n, m = map(int, input().split())
mat = [list(map(int, input().strip().split())) for _ in range(n)]
haveToVisit = [list(map(int, input().strip().split())) for _ in range(m)]
visited = [[0] * n for _ in range(n)]
casesCount = 0
search(haveToVisit[0][0], haveToVisit[0][1], 0)

print(casesCount)