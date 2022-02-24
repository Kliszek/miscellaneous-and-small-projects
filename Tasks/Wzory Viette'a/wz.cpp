#include <iostream>
#include <cmath>

using namespace std;



double a,b,c;

double ilo, suma;


int main()
{
    cout<<"Rownanie kwadratowe:\n";

    do
    {
        cout<<"a = ";
        cin>>a;
    }
    while(a==0);



    cout<<"b = ";
    cin>>b;




    cout<<"c = ";
    cin>>c;

    if(a==1)cout<<"\nxx ";
    else if(a==-1)cout<<"\n-xx ";
    else cout<<"\n"<<a<<"xx ";

    if(b!=0)
    {
    if(b>=0)cout<<"+";
    if(b==1)cout<<"x ";
    else if(b==-1)cout<<"-x ";
    else cout<<b<<"x ";
    }
    if(c!=0)
    {
    if(c>=0)cout<<"+";
    cout<<c;
    }

    ilo=c/a;
    suma=-b/a;

    cout<<"\n\nx1 * x2 = "<<ilo<<"\nx1 + x2 = "<<suma;



    double delta=b*b-4*a*c;

    cout<<"\n\nDelta = "<<delta;

    double x1,x2;
    if(delta>0)
    {
        x1=(-b-sqrt(delta))/(2*a);
        x2=(-b+sqrt(delta))/(2*a);
        cout<<"\nPierwiastek z delty = "<<sqrt(delta);
        cout<<"\n\nx1 = "<<x1<<"\nx2 = "<<x2;
    }
    else if(delta==0)
    {
        x1=(-b)/(2*a);
        cout<<"\n\nx = "<<x1;
    }

    else if(delta<0)
        cout<<"\n\nDelta jest ujemna!\n";



    cin.sync();
    cin.get();
}
