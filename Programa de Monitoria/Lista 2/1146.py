while True:
    x = int(input())
    if x == 0:
        break
    i = 1
    while i <= x:
        if (i < x ):
            print(i, end = " ")
        
        if (i == x ):
            print(i, end = "\n")
        i += 1