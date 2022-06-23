#
#
# Range and Flying Time of cannon under linear resistant
# Chen Sheng Wen
# June 20,2022
#

import numpy as np
BETA = 0.001
VINI = 600.0
GRAV = 9.8
VTERMINAL = GRAV/BETA
THETADEGREE = 1.0


def xoft(t,VINIX,BETA):
    y = VINIX/BETA*(1.0-np.exp(-BETA*t))
    return y

def yoft(t,VINIY,VTERMINAL,BETA):
    y = ((VINIY+VTERMINAL)/BETA)*(1.0-np.exp(-BETA*t))-VTERMINAL*t
    return y
def vyoft(t,VINIY,VTERMINAL,BETA):
    vy = (VINIY+VTERMINAL)*np.exp(-BETA*t)-VTERMINAL
    return vy

while(THETADEGREE<90.0):
    THETA=THETADEGREE*np.pi/180.0
    VINIX = VINI * np.cos(THETA)
    VINIY = VINI * np.sin(THETA)
    t = 2.0*VINIY/GRAV
    ncount = 0
    while True:
        dt = yoft(t,VINIY,VTERMINAL,BETA)/vyoft(t,VINIY,VTERMINAL,BETA)
        t = t - dt
        ncount += 1
        print(t)
        Y.append(yoft(t,VINIY,VTERMINAL,BETA))
        X.append(xoft(t,VINIX,BETA))
        if (abs(dt)<1.0e-12):
            break
        print(abs(dt))
    range = xoft(t,VINIX,BETA)

    print(f"When theta = {THETADEGREE} degree") 
    print(f"Flying time :{t}")
    xt = xoft(t,VINIX,BETA)
    print(f"Range= {xt}")
    yt = yoft(t,VINIY,VTERMINAL,BETA)
    print(f"y(t) = {yt}")
    print(f"Converge in {ncount}")
    THETADEGREE += 1.0
