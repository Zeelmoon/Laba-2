
#include <iostream>
#include <clocale>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x)
{
    return atan(x);
}
double F(double x, int n) 
{
    return ((pow(-1, n) * (pow(x, 2 * n + 1) / (2 * n + 1))));
}

double rad_n(double x, int n)
{
    if (n == 0)
        return x;
    double t = F(x,n);
    return (t + rad_n(x, n - 1));
    
}
double rad_e(double x, int n , double s)
{
    double e = 0.00001;
    if (n == 0) 
    {
        s = x;
        return s;
    }
    double x1 = F(x,n);
    double s1 = rad_e(x, n - 1, s) + x1;
    if (abs(s1 -s)<e)
    {
        return s1;
    }
    s = s1;
    return s;
}
int main()
{
    cout << fixed << setprecision(6);
    double s = 0.0;
    double a = 0.1;
    double b = 1.0;
    int n = 40;
    double shag = (b - a) / 10;
    for (double x = a; x <= b;x += shag) 
    {
        double Sn = rad_n(x, n);
        double Se = rad_e(x,n,s);
        double y = f(x);
        cout << "x = " << x << "  Sn = " << Sn << "  Se = " << Se << "  y = " << y << endl;
    }
    return 0;

}
