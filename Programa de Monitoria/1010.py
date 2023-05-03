# leitura dos dados da peça 1
codigo_peca_1, numero_peca_1, valor_unitario_1 = input().split()
codigo_peca_1 = int(codigo_peca_1)
numero_peca_1 = int(numero_peca_1)
valor_unitario_1 = float(valor_unitario_1)

# leitura dos dados da peça 2
codigo_peca_2, numero_peca_2, valor_unitario_2 = input().split()
codigo_peca_2 = int(codigo_peca_2)
numero_peca_2 = int(numero_peca_2)
valor_unitario_2 = float(valor_unitario_2)

# cálculo do valor a ser pago
valor_total = numero_peca_1 * valor_unitario_1 + numero_peca_2 * valor_unitario_2

# exibição do resultado na tela
print("VALOR A PAGAR: R$ {:.2f}".format(valor_total))