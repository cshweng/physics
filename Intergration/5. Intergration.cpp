//*******************************************
//intergration calss and function class test
//CHEN SHENG WEN
//2022 06 20
//*******************************************
#include <cmath>
using namespace std;

class function
{
 //   double theta0 ,xi0 ;  to be constructer
    //
    double aconst;
    public:
        function(){};
        function(const double t)
          {
            this->aconst = t;
          }
        //function (const double th) {this->theta0 = th;}
        double f(const double x) const
            {   double x2, x3;
                x2 = x * x;
                x3 = x2 * x;
                return ( (3.0*x2 - x3) * exp(-x) + aconst);
            }
        double F(const double x)const
            {
                return (x*x*x*exp(-x) + aconst  * x);
            }
};

class integral
{
     // int ngrid;//know how muck point
      double uplimit, lowlimit; //gridwidth,
      function intg;
    public:
      integral(const double a, const double b, function intf)//intgral function
            {
                this->lowlimit = a;
                this->uplimit = b;
                this->intg = intf;
            }
      double tropazoid (const int n) const
            {
                double h, sum, x;  //x = initial
                int i;
                h = (this->uplimit - this->lowlimit) / (double)n;
                x = this->lowlimit;
                sum = 0.0;
                for (i=1 ; i<n ; i++)
                    {
                        x = this->lowlimit + h * (double)i;
                        sum += this->intg.f(x);
                    }
                        sum *= 2.0;
                        sum += this->intg.f(this->lowlimit) + this->intg.f(this->uplimit);
                    return (sum * h /2.0);
            }
        double simpson(const int n ) const
            {
                int i;
                double h, sum4, sum2, sum , x;
                h = (this->uplimit - this->lowlimit) / (double)n;
                sum4 = 0.0;
                 for (i=1 ; i<n ; i+=2)
                   {
                        x = this->lowlimit + h * (double)i;
                        sum4 += this->intg.f(x);
                   }
                sum2 = 0.0;
                 for (i=1 ; i<(n-1) ; i+=2)
                   {
                        x = this->lowlimit + h *(double)i;
                        sum2 += this->intg.f(x);
                   }
                sum = 2.0 * sum2 + 4.0 * sum4 + this->intg.f(this->lowlimit) + this->intg.f(this->uplimit);
                return (h * sum / 3.0);
            }
};// end of calss integral

#include <iostream>
#include <iomanip>
int main()
{
    function fx(2.0);
    double a, b;
    int npts = 1000;
    a = 0.0;
    b = 10.0;
    integral intg(a, b, fx);
    cout << setprecision(15);
    cout << "method T : " << intg.tropazoid(2000) << endl;
    cout << "methis S : " << intg.simpson(2000) <<endl;
    cout << "   Exact = " << (fx.F(b) - fx.F(a)) << endl;
    return 0;
}

