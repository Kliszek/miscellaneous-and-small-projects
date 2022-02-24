#include <iostream>

using namespace std;



int n, mod;

int naj=0, d=0, t,p=-1;

int main()
{
    cin>>n>>mod;


    for(int i=0; i<n; i++)
    {
        cin>>t;
        t=mod%t;
        if(t>p) d++;
        else d=0;
        if(d>naj) naj=d;
        p=t;
    }
    cout<<naj;
}
