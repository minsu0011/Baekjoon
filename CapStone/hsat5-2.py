import sys
from collections import Counter
input = sys.stdin.readline
N = int(input())
scoreList = []
totalScore = [0] * N
for _ in range(3):
    ipt = list(map(int, input().strip().split()))
    scoreList.append(ipt[:N])
    for i in range(N):
        totalScore[i] += ipt[i]
scoreList.append(totalScore)

for score in scoreList:
    scoreCounter = Counter(score)
    scoreSet = list(set(score))
    scoreSet.sort(reverse=True)
    scoreDict = dict()

    token = 1
    for s in scoreSet:
        scoreDict[s] = token
        token += scoreCounter[s]

    result = []
    for i in score:
        result.append(scoreDict[i])
    print(*result, sep=' ')