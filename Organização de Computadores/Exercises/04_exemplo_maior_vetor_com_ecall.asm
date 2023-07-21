# Implementa um programa que encontra o maior valor presente em um vetor:
#
# maior = vetor[0];
# for (x = 1; x < 10; x++)
#     if(vetor[x] > maior)
#       maior = vetor[x]
#
#
#
	.data
vetor: 	.word	7, 3, 4, 1, 5, 9, 6, 2, -1, -15
tamanho: .word	10
msg:    .asciz  "O maior valor do vetor eh: "

	.text

main:
	la	t0, vetor		# t0 recebe o endereço de memória do inicio do vetor
	lw	s0, 0 (t0)		# lê o primeiro elemento do vetor; 
	mv	s1, s0			# maior = vetor[0]
	li	s2, 1			# x = 1
	li  	t1, 10			# tmp = 10
teste:
	beq	s2, t1, imprime	# testa se percorreu todo o vetor
	addi 	t0, t0, 4		# aponta para a próxima posição do vetor
	lw	s0, 0 (t0)		# lê o elemento do vetor vetor[x]
	bgt	s1, s0, atualiza_x
novo_maior:
	mv 	s1, s0			# faz maior = vetor[x]

atualiza_x:
	addi 	s2, s2, 1
	j teste

imprime: 

	li a7, 4
	la a0, msg
	ecall

	li a7, 1
	mv a0, s1
	ecall

	li a7, 10
	ecall
