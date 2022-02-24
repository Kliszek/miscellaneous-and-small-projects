#include <iostream>

using namespace std;



long long N,K;
bool rosl[1000002];


int main()
{
#define int long long
    ios_base::sync_with_stdio(false);
    cin>>N>>K;

    int roz=0;
    for(int i=0; i<N; i++)
    {
        cin>>rosl[i];
        if(rosl[i]==1) roz++;
    }
    if(roz<K)
    {
        cout<<"NIE";
        return 0;
    }

    int a=0, b=0;
    roz=rosl[0];
    //if(rosl[0]==1) roz++;

    int najm=N-1;

    while(a<N)
    {
        if(roz<K && b!=N)
        {
            b++;
            if(rosl[b]==1)
            {
                roz++;
            }
        }
        else
        {
            if(rosl[a]==1) roz--;
            a++;
        }

        if(roz==K && najm>b-a-roz+1) najm=b-a-roz+1; //b-a-roz+1 = iloœæ kapust pomiedzy a i b
    }

    cout<<najm;
}
