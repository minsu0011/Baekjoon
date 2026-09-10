import sys
input = sys.stdin.readline
T = int(input())
listT = []
for _ in range(T):
    N = int(input())
    listT.append(list(map(int, input().strip().split()))[:N])

# N <= 100000
# 300 <= mi <= 900
# input sum of N <= 200000

for t in range(T):
    microServerCount = 0
    memoryCount = [0] * 601
    for n in range(len(listT[t])):
        if listT[t][n] > 600:
            microServerCount += 1
        else:
            memoryCount[listT[t][n]] += 1
    
    for i in range(600, 299, -1):
        if memoryCount[i] == 0:
            continue

        while memoryCount[i] > 0:
            memoryCount[i] -= 1
            remainMemory = 900 - i

            for j in range(min(remainMemory, i), 299, -1):
                if remainMemory < 300:
                    break
                if(memoryCount[j] == 0):
                    continue

                maxServiceCount = min(remainMemory // j, memoryCount[j])
                memoryCount[j] -= maxServiceCount
                remainMemory -= maxServiceCount * j
            
            microServerCount += 1

    print(microServerCount)

        

