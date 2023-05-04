N = int(input())
i = 0
while i < N:
    n = int(input())
    j = 1
    soma = 0
    while j < n:
        if (n % j)== 0:
            soma += j 
        j += 1
    if soma == n:
        print(f"{n} eh perfeito")
    else :
        print(f"{n} nao eh perfeito")
    i += 1