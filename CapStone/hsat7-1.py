import sys
input = sys.stdin.readline
n, q = map(int, input().split())
listn = list(map(int, input().strip().split()))[:n]
listq = [int(input()) for _ in range(q)]
listn.sort()
dictn = {}
index = 1
for i in range(n):
    dictn[listn[i]] = index
    index += 1
for l in listq:
    if l in dictn:
        idx = dictn[l] - 1
        print(idx * (n - idx - 1))
    else :
        print(0)
    