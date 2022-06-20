//
//
//
//
//
//
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
#include<interpolation.h>

int main(int navg, char *aavg[])
{
    int ndata,i,imax, nintp, nintp0;
    double *xdata, *ydata, rmax, rtmp;
    ifstream datafile("range.txt");
    datafile>>ndata;
    xdata = new double [ndata];
    ydata = new double [ndata];
    for (i=0; i <ndata ; i++)
    {
        datafile>>xdata[i]>>ydata[i];
    }
    datafile.close();
    imax=0;
    rmax=ydata[imax];
    for (i=0; i<ndata; i++)
    {
        rtmp = ydata[i];
        if(rtmp>rmax)
        {
            imax = i;
            rmax = rtmp;
        }
    }
    nintp=6;
    nintp0= imax-nintp/2 -1;
    if (nintp0<0) nintp0 = 0;
    if ((nintp0 + nintp)>= ndata) nintp0 =ndata - nintp;

    interp range (nintp,&xdata[nintp0],&ydata[nintp0]);
    //***************************************************************************
    //begin the secant method to find the zero of range's derivative
    //***************************************************************************
    double x1,x2,x3,y1,y2,y3;
    x1 = range(0);
    x2 = range(range.n()-1);
    y1 = range.df(x1);
    y2 = range.df(x2);
    do
    {
        x3= x2-y2/(y2-y1)*(x2-x1);
        x1=x2;
        x2=x3;
        y1 = range.df(x1);
        y2 = range.df(x2);
    }while (abs(x1-x2)>1.0e-8);
    cout<<"Max range found at angle "<< x2 ;
}
