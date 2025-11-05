import sys
from collections import deque

def dfs(node, parent, previousWeight):
    global sumList
    sumList[1] += previousWeight
    for neighbor, weight in neighborList[node]:
        if neighbor == parent:
            continue
        dfs(neighbor, node, previousWeight + weight)

def findSubtreeCount(node, parent):
    subTreeCount[node] = 1
    for neighbor, weight in neighborList[node]:
        if neighbor == parent:
            continue
        findSubtreeCount(neighbor, node)
        subTreeCount[node] += subTreeCount[neighbor]

def dfs2(node, parent):
    global sumList
    for neighbor, weight in neighborList[node]:
        if neighbor == parent:
            continue
        sumList[neighbor] = sumList[node] + (N - 2 * subTreeCount[neighbor]) * weight
        dfs2(neighbor, node)

input = sys.stdin.readline
N = int(input())
neighborList = [[] for _ in range(N + 1)]

for i in range(1, N):
    ipt = list(map(int, input().strip().split()))
    neighborList[ipt[0]].append([ipt[1], ipt[2]])
    neighborList[ipt[1]].append([ipt[0], ipt[2]])


sumList = [0] * (N + 1)
dfs(1, 0, 0)

subTreeCount = [0] * (N + 1)
findSubtreeCount(1, 0)

dfs2(1, 0)
print(*sumList[1:], sep='\n')