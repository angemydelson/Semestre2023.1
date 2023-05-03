N = int(input())
i = 1
a = 0
b = 1
while i < N:
    print(a, end=" ")
    a, b = b, a + b
    i += 1
if N > 1:
    print(a)