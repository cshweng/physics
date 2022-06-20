//
//
// Newton's method & Aitken accelation implemented for finding multiple root
// Chen Sheng Wen C24995059
// Sebtember 25,2013
//
#include <cmath>
#include <iostream>
#include <cstdlib>
using namespace std;

//Newton's Method
//function1(f(x)=exp(x)-x^2)
double fun1(double x)
{
    double y;
    y = exp(x)-x*x;
    return y;
}
double dfun1(double x)//gobal variable
{
    return (exp(x)-2.0*x);
}

//function2(f(x)=(x-2.5)^4)
double fun2(double x)
{
    double y;
    y = x -2.5;
    return pow(y,4.0);
}
double dfun2(double x)
{
    double y;
    y = x - 2.5;
    return 4.0*pow(y,3.0);
}

//Aitken accelation implemented for finding multiple root

int main()
{
    double x,x1,x2,dx;
    int ncount;
//call fuction2
    double fun2(double),dfun2(double);//local variable
    x=0.0;
    ncount=0;
    do
    {
        x1 =x-fun2(x)/dfun2(x);
        x2 =x1-fun2(x1)/dfun2(x1);
        dx = pow((x2 - x1),2.0)/(x+x2-2.0*x1);
        x = x - dx;
        ncount = ncount+1;
    }while(abs(dx)>1.0e-10);
    cout<<"Root = "<<x<<"\n";
    cout<<"f(x) = "<<fun2(x)<<"\n";
    cout<<"Converge in "<< ncount <<" iteration\n";
    return 0;
    system("pause");
}
