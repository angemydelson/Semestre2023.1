#  Resolve a equação:
#    X = (A - B) + (C - 5)
#  Registradores previamente mapeados
#  s0 <- A
#  s1 <- B
#  s2 <- C
#  s3 <- X

    .data

	.text

main: 
    sub t0, s0, s1    # isto é um comentário
    addi t1, s2, -5
    add s3, t0, t1
