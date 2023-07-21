# Implementa Pseudo-codigo:
#   if (x < 10)
#       y = y + 1
#   else
#       y = -1
#
#  Registradores mapeados
#   s0 <- x
#   s1 <- y
#

	.data

	.text
main:
	addi t0, zero, 10       # atribui 10 para t0

	blt s0, t0, true        # faz teste (x < 10)
else:
   	addi s1, zero, -1       # corpo do else
	j	 fim                # desvia para não executar o corpo do if
true:
   	addi s1, s1, 1          # corpo do if
   
fim:
	nop
