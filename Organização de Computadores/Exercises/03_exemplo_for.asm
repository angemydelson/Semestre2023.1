# Implementa o pseudo-código:
#  for(x = 0; x < 10; x++)
#     z = z + x;
#
# Registradores mapeados
#  s0 <- x
#  s1 <- z

	.data

	.text
main:
	
inicializa:
	addi t0, zero, 10   # carrega 10 em t0, utilizado como auxiliar para depois fazer o teste
	add  s0, zero, zero # inicializa x com 0
condicao:
	beq s0, t0, fim     # testa condição de parada do laco: quando x for igual a 10 vai para o fim
corpo:
	add s1, s1, s0		# executa o corpo do laco
atualiza:
	addi s0, s0, 1      # atualiza a variavel de controle
	j condicao          # volta para o teste da condicao de parada
fim:
	nop
