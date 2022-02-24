#include <iostream>

using namespace std;




int a,b;


void rozklad(int x)
{
    bool a=false;
    int l=x;
    for(int i=2; i<=l/2; i++)
    {
        if(x%i==0)
        {
            if(a)cout<<"*";
            cout<<i;
            x/=i;
            i--;
            a=true;
        }


    }
    if(!a) cout<<l;
}





int main()
{
    cin>>a>>b;

    rozklad(a);
    for(int i=a+1; i<=b; i++)
    {
        cout<<"\n";
        rozklad(i);
    }

}
