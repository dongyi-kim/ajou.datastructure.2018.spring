import os
import sys
import random

if len(sys.argv) != 4:
    print("USAGE python data_gen.py FOLDER, V, E")
    exit(-1)

FOLDER = sys.argv[1]
V = int(sys.argv[2])
E = int(sys.argv[3])

edges = []
for i in range(V - 1):
    u = i + 1
    v = i
    w = 1000
    edges.append((u, v, w))

while len(edges) < E:
    u = random.randint(0, V - 1)
    v = random.randint(0, V - 1)
    w = random.randint(0, 1000)
    edges.append((u, v, w))

random.shuffle(edges)

with open(os.path.join(FOLDER, 'input.txt'), 'w') as fout:
    fout.write('%d %d\n' % (V, E))
    for edge in edges:
        fout.write('%d %d %d\n' % edge)
