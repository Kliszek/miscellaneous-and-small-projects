#include <iostream>



using namespace std;

int n;
int a;
int suma;
int p;

int dodaj(int t)
{
    suma=0;
    while(t>=10)
        {
            suma+=(t%10)*(t%10);
            t=t/10;
        }

        suma+=t*t;


    return suma;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a;

        p=1;
        while(a!=4 && a!=1)
        {
            //cout<<a<<" ";
            a=dodaj(a);
            p++;
        }
        cout<<p<<"\n";

    }
}
