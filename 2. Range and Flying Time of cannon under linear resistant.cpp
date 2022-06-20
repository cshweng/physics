//
//
// Range and Flying Time of cannon under linear resistant
// Chen Sheng Wen C24995059
// October 2,2013
//
#include <cmath>
#include <cstdio>
#define BETA  0.01
#define VINI  600.0
#define GRAV   9.80
using namespace std;
struct parameter
{
    double vini;
    double beta;
    double vinix,viniy;
    double vterminal;
};


double xoft(double t, parameter q)
{
    double y;
    y = q.vinix/q.beta*(1.0-exp(-q.beta*t));
    return y;
}

double vxoft(double t,parameter q)
{
    double y;
    y = q.vinix*exp(-q.beta*t);
    return y;
}
double yoft(double t,parameter q)
{
    double y;
    y= ((q.viniy + q.vterminal)/q.beta )*(1.0-exp(-q.beta*t))-q.vterminal*t;
    return y;
}


double vyoft(double t,parameter q)
{
    double vy;
    vy = (q.viniy + q.vterminal)*exp(-q.beta*t)-q.vterminal;
    return vy;
}


int main()
{
    parameter p;
    double t,dt,theta,range,thetadegree;
    int ncount;

    FILE *fpt;
    fpt= fopen("range.txt","w");
    p.vini=VINI;
    p.beta=BETA;
    p.vterminal = GRAV/p.beta;
    thetadegree=1.0;
    fprintf(fpt,"Range and Flying Time of cannon under linear resistant\n\n");

  while(thetadegree<90.0)
    {



        theta=thetadegree*M_PI/180.0;

        p.vinix= p.vini * cos(theta);
        p.viniy= p.vini * sin(theta);
        t = 2.0*(p.viniy)/GRAV;
        ncount = 0;
            do
            {
                dt = yoft(t,p)/vyoft(t,p);
                t = t - dt;
                ncount= ncount +1;
            }while(abs(dt)>1.0e-12);

        range = xoft(t,p);
        printf("When theta = %.12f",thetadegree);
        printf(" degree\n");
        fprintf(fpt,"When theta = %.12f",thetadegree);
        fprintf(fpt," degree\n");
        printf("Flying time = %.12f",t);
        printf(" m\n");
        fprintf(fpt,"Flying time = %.12f",t);
        fprintf(fpt," m\n");
        printf("Range = %.12f",xoft(t,p));
        printf(" s\n");
        fprintf(fpt,"Range = %.12f",xoft(t,p));
        fprintf(fpt," s\n");
        printf("y(t) = %.12f\n",yoft(t,p));
        fprintf(fpt,"y(t) = %.12f\n",yoft(t,p));
        printf("Converge in  %d\n",ncount);
        printf("\n");
        fprintf(fpt,"\n");
        thetadegree=thetadegree+1.0;
    }
    fclose(fpt);
return 0;
}
