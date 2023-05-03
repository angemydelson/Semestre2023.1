a = int(input())
b = int(input())
soma = 0

if a >= b:
    i = a - 1
    while i > b:
        if i < 0 :
            teste = abs(i)
            if (teste % 2 != 0):
                soma += i
        else :    
            if (i % 2 != 0):
                soma += i
        i -= 1
    print(soma)
else:
    i = a + 1
    while i < b:
        if i < 0 :
            teste = abs(i)
            if (teste % 2 != 0):
                soma += i
        else :    
            if (i % 2 != 0):
                soma += i
        i += 1
    print(soma)