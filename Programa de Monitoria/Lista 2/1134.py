alcool = 0
gasolina = 0
diesel = 0
while True:
    tipoCombustivel = int(input())
    i = tipoCombustivel
    if (i == 1):
        alcool += 1
    else :
        if i == 2:
            gasolina += 1
        else :
            if i == 3:
                diesel += 1
            else :
                if i == 4:
                    break
                else :
                    continue
    i += 1
print("MUITO OBRIGADO")
print(f"Alcool: {alcool}\nGasolina: {gasolina}\nDiesel: {diesel}")
