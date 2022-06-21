
import math

def fun1 (x):
    y = math.exp(x)-x*x
    return y

def dfun1(x):
    return (math.exp(x)-2.0*x)

def fun2(x):
    y = x-2.5
    return y**4.0
    
def dfun2(x):
    y = x-2.5
    return 4.0*y**3.0

x=0.0
ncount=0
while True:
    x1 =x-fun2(x)/dfun2(x)
    x2 =x1-fun2(x1)/dfun2(x1)
    dx = pow((x2 - x1),2.0)/(x+x2-2.0*x1)
    x = x - dx
    ncount = ncount+1
    if (abs(dx)<1.0e-10):
        break
print(f"Root = {x}")
df2x = fun2(x)
print(f"f(x) = {df2x}")
print(f"Converge in {ncount}")