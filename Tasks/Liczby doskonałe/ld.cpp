#include <iostream>

using namespace std;



long long n;
long long a=1;
long long suma=1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    if(n%2==0) suma+=2;
    else a++;

    for(long long i=3; i<=n/2; i+=a)
    {
        if(n%i==0)
        {
            suma+=i;
        }
    }

    if(suma==n)cout<<"TAK";
    else cout<<suma;

}
