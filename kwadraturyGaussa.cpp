#include <iostream>
#include<cmath>
using namespace std;

double gaussChebyshev(int n);
double gaussLegendre(int n);
double gaussLaguerre(int n);
double gaussHermite(int n);
int main()
{
    cout<<"a) wartosc kwadratury Gaussa-Chebysheva dla n=3: ";
    cout << gaussChebyshev(3) << endl;
    cout<<"b) wartosc kwadratury Gaussa-Legendre'a dla n=4: ";
    cout<<gaussLegendre(4)<<endl;
    cout<<"c) wartosc kwadratury Gaussa-Laguerre'a dla n=3: ";
    cout<<gaussLaguerre(3)<<endl;
    cout<<"d) wartosc kwadratury Gaussa_Hermite'a dla n=4: ";
    cout<<gaussHermite(4);

    return 0;
}
double gaussChebyshev(int n)
{
    double pierwiastki[n+1];
    double Hj=0;
    double wynik=0;
    for(int j=0;j<=n;j++)
    {
        pierwiastki[j]= cos(((2*j+1)*M_PI)/(2*(n+1)));//M_PI pi zdefiniowane w cmath
    }
    Hj= M_PI/(n+1);
    for(int i=0;i<=n;i++)
    {
        wynik+=Hj*pow(pierwiastki[i],2);
    }
    return wynik;
}
double gaussLegendre(int n)
{
    double pierwiastki[n+1]={-0.906180,-0.538469,0,0.538469,0.906180};
    double Hj[n+1]={0.236927, 0.478629, 0.568889, 0.478629, 0.236927};
    double wynik=0;
    for(int i=0;i<=n;i++)
    {
        wynik+=Hj[i]*(1.0/(sqrt(1+pow(pierwiastki[i],2))));
    }
    return wynik;
}
double gaussLaguerre(int n)
{
    double x[n+1]={0.322548, 1.745761, 4.536620, 9.395071};
    double Hj[n+1]={0.603154, 0.357419, 0.038888, 0.000539};
    double wynik=0;
    for(int i=0;i<=n;i++)
    {
        wynik+=Hj[i]*pow(M_E, -x[i])*sin(x[i])/x[i];
    }
    return wynik;
}
double gaussHermite(int n)
{
    double x[n+1]={-2.020183, -0.958572, 0, 0.958572, 2.020183};
    double Hj[n+1]= {0.019953, 0.393619, 0.945309, 0.393619, 0.019953};
    double wynik=0;
    for(int i=0;i<=n;i++)
    {
        wynik+=Hj[i]*cos(x[i]);
    }
    return wynik;

}
