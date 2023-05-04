while True:
    N = int(input())
    caraM = 0
    coroaJ = 0
    if N == 0:
        break
    entradas = input().split()
    for i in range(N):
        entrada = int(entradas[i])
        if entrada == 0:
            caraM += 1
        else :
            if entrada == 1:
                coroaJ += 1
    print(f"Mary won {caraM} times and John won {coroaJ} times")
