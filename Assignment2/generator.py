import random 

N = 10
M = 100
print('%d %d' % ( N , M ) )
for i in range(M):
    u = random.randint(0, N-1)
    v = random.randint(0, N-1)
    w = random.randint(1, 20)
    print('%d %d %d' % (u, v, w ))
