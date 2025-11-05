import sys
from collections import deque
input = sys.stdin.readline
N, K = map(int, input().strip().split())

childrenList = []
childrenList.append([])  # 0th index is unused
requestList = [0] * (N + 1)
requestList[1] = K
inDegree = [0] * (N + 1)

for i in range(1, N + 1):
    tmpList = list(map(int, input().strip().split()))
    if(len(tmpList) == 1):
        childrenList.append([])
    else:
        for child in tmpList[1:]:
            inDegree[child] += 1
        childrenList.append(tmpList[1:])

queue = deque()

for i in range(1, N + 1):
    if inDegree[i] == 0:
        queue.append(i)

while queue:
    node = queue.popleft()
    childCount = len(childrenList[node])
    if childCount == 0:
        continue
    rest = requestList[node] % childCount
    for child in childrenList[node]:
        requestList[child] += requestList[node] // childCount
        if rest > 0:
            requestList[child] += 1
            rest -= 1
        inDegree[child] -= 1
        if inDegree[child] == 0:
            queue.append(child)

print(*requestList[1:], sep=' ')