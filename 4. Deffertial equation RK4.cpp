//
//
//
//
//

#include<cstdio>
#include<cmath>
#include"xyplot2.h"
#include"graphics.h"
using namespace std;

class twod
{
    double x,y;
public:
    twod(){;}
    twod(const double r1,const double r2) {x=r1; y=r2;}
    friend twod operator+ (const twod&, const twod&);
    friend twod operator- (const twod&, const twod&);
    friend twod operator* (const double, const twod&);
    friend twod operator* (const twod&, const double);
    friend twod operator/ (const twod&, const double);
};
twod operator+(const twod&a, const twod&b)
{
    return twod (a.x+b.X, a.y-b.y);
}


twod slopf(double x,twod y)
{
    return twod(y.y, -2.0*gamma*y.y-w2*y.x +drivf(x));
}

double exactf(double x)
{
    return exp(x*x*x/3.0);
}
int main()
{
    double xini,yini,x,y,xt,yt,k1,k2,k3,k4,h,h2;
    double *xpt,*ypt;
    int i, nstep;

    x =xini =0.0;
    y =yini =1.0;
    h= 0.01;
    h2=h/2.0;
    nstep = 100;
    xpt = new double[nstep+1];
    ypt = new double[nstep+1];
    xpt[0]=x;
    ypt[0]=y;
    for (i=0; i<nstep; i++)
    {
        k1 = slopf(x,y);
        xt = x+h2;
        yt = y +k1*h2;
        k2 = slopf(xt,yt);
        yt = y+k2*h2;
        k3 = slopf(xt,yt);
        xt = x+h;
        yt = y+k3*h;
        k4 = slopf(xt,yt);
        y += (k1 +2.0*(k2+k3)+k4)*h/6;
        x  = xini + (double)(i+1)*h;
        xpt[i+1]=x;
        ypt[i+1]=y;

        if((i%10)==0)
        {
            printf("x=%7.3lf   y=%.15lf  %.15lf\n",x,y,exactf(x));
        }
    }
    graph pp(xpt,ypt,nstep);
    pp.plot();
    system("pause");
    return 0;
}
