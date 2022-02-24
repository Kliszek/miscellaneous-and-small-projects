#include <iostream>

using namespace std;

int n;


int dzielnik;
int t;


int nwd(int a,int b)
{
    int c;
    while(b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin>>dzielnik;
    for(int i=1; i<n; i++)
    {
        cin>>t;
        dzielnik=nwd(dzielnik,t);
        //cout<<"Dzielnik: "<<dzielnik<<"\n";
    }




    cout<<dzielnik;
}
