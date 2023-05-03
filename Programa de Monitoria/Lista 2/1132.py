a = int(input())
b = int(input())
soma = 0

if a >= b:
    i = a 
    while i >= b:
        if i < 0 :
            teste = abs(i)
            if (teste % 13 != 0):
                soma += i
        else :    
            if (i % 13 != 0):
                soma += i
        i -= 1
    print(soma)
else:
    i = a 
    while i <= b:
        if i < 0 :
            teste = abs(i)
            if (teste % 13 != 0):
                soma += i
        else :    
            if (i % 13 != 0):
                soma += i
        i += 1
    print(soma)