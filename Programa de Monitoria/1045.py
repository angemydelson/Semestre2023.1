A,B,C = input().split()
A = float(A)
B = float(B)
C = float(C)
if A >= B+C:
    print("NAO FORMA TRIANGULO")

elif A**2 == B**2 + C**2:
    print("TRIANGULO RETANGULO")
    
elif A**2 > B**2 + C**2:
    print("TRIANGULO OBTUSANGULO")
        
elif A**2 < B**2 + C**2:
    print("TRIANGULO ACUTANGULO")
            
if A == B and A == C and B == C:
    print("TRIANGULO EQUILATERO")

elif A == B or A == C or B == C:
    print("TRIANGULO ISOSCELES")
                        

        

        
