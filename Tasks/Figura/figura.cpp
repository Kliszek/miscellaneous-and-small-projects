#include <iostream>

using namespace std;

\
double C;
double dokl;
//–x^2/50
//1+x^2/100-x/200
//dok³adnoœæ 0,01




double f(double x)
{
    return x*x/50*(-1);
}
double g(double x)
{
    return 1+x*x/100-x/200;
}


double POLE;

int main()
{
    C=10;//cin>>C;
    dokl=0,01;//cin>>dokl;
    int czesci=2;

    double pole1=(g(0)+g(C))/2*C;
    //cout<<"Pole 1:"<<pole1<<"\n";
    double pole2=(g(0)+g(C/2))/4*C + (g(C/2)+g(C))/4*C;
    //cout<<"Pole 2:"<<pole2<<"\n";
    while(pole1-pole2>dokl)
    {
        czesci*=2;
        double c=C/czesci;
        pole1=pole2;
        pole2=0;
        for(int i=0; i<czesci; i++)
        {
            pole2+=(g(c*i)+g(c*(i+1)))/2*c;
        }
    }
    cout<<"a)\nPole gornej czesci: "<<pole2<<"\n";
    POLE=pole2;


    czesci=2;

    pole1=(f(0)+f(C))/2*C;
    pole2=(f(0)+f(C/2))/4*C + (f(C/2)+f(C))/4*C;
    while(pole1-pole2<dokl)
    {
        czesci*=2;
        double c=C/czesci;
        pole1=pole2;
        pole2=0;
        for(int i=0; i<czesci; i++)
        {
            pole2+=(f(c*i)+f(c*(i+1)))/2*c;
        }
    }
    cout<<"Pole dolnej czesci: "<<pole2<<"\n";

    POLE-=pole2;
    cout<<"\nRazem: "<<POLE;






    //ZAD2

    int a=5;
    while(g(a)-f(a)<26)
    {
        a++;
    }
    cout<<"\n\nb): C="<<a+100;
}
