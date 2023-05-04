
while True:
    N = int(input())
    i = 0
    caraM = 0
    coroaJ = 0
    if N == 0:
        break
    while i < N:
        entrada = int(input())
        if entrada == 0:
            caraM += 1
        else :
            if entrada == 1:
                coroaJ += 1
        i += 1
    print(f"Mary won {caraM} times and John won {coroaJ} times")