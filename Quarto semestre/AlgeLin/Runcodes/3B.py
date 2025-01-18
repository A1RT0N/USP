import numpy as np

# dado uma matriz A e um ângulo X, retorna rot(X).A em np
def rot(A, x):
    rad = np.deg2rad(x)
    rot = np.array([(np.cos(rad), -np.sin(rad)), (np.sin(rad), np.cos(rad))])
    
    return np.dot(rot,A)

# dado uma matriz A e transalação em x e y, retorna trans(X).A em np
def trans(A, sx,sy):
    trans = np.array([(sx,0), (0,sy)])
    
    return np.dot(trans, A)  
    
    
d = int(input())

a = [(0,1), (1,0)]

var = np.array(a)

for _ in range(d):
    action = tuple(input().split(' '))
    
    if(action[0] == 'R'):
        var = rot(var,float(action[1]))
        
    else:
        var = trans(var, float(action[1]), float(action[2]))
        
    
if(np.linalg.det(var) == 0):
    print("SemVerTia")
else:
    print("SimTia, te vejo!")
