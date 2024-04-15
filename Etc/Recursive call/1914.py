N = int(input())
print(2**N-1)
def hanoi_sequence(N, fro, to, by):
    if N>20 :
        return
    if N==1 :
        print(fro, to, sep = " ")
        return
    hanoi_sequence(N-1, fro, by, to)
    print(fro, to, sep=" ")
    hanoi_sequence(N-1, by, to, fro)

hanoi_sequence(N, 1, 3, 2)
