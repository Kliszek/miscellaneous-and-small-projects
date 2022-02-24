#include <iostream>
using namespace std;



long long x;

int main()
{
    cin>>x;
    if(x==1)
    {
        cout<<1;
        return 0;
    }
    if(x==2)
    {
        cout<<2;
        return 0;
    }
    if(x==3)
    {
        cout<<2;
        return 0;
    }



    int d=2;
    int s=1;
    int dzielnikow=1;

    while(x!=1)
    {
        if(x%d==0)
        {
            s++;
            x/=d;

        }
        else
        {
            d++;
            dzielnikow*=s;
            s=1;
        }
    }
    dzielnikow*=s;

cout<<dzielnikow;
    }
