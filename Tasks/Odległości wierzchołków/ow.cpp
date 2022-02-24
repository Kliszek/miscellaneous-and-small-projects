#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m,n;

vector <int> S[1000003];

queue <int> K;





int main()
{
    cin>>n>>m;

    int t1,t2;
    for(int i=0; i<m; i++)
    {
        cin>>t1>>t2;
        S[t1].push_back(t2);
        S[t2].push_back(t1);
    }

    int odl[n+1];
    for(int i=0; i<n+1; i++)
    {
        odl[i]= -1;
    }
    odl[1]=0;

    K.push(1);

    int w;

    while(!K.empty())
    {
        w=K.front();
        for(int i=0; i<S[w].size(); i++)
        {
            if(odl[S[w][i]]== -1)
            {
                K.push(S[w][i]);
                odl[S[w][i]]=odl[w]+1;
            }
        }
        K.pop();

    }
for(int i=1; i<=n; i++)
{
    cout<<odl[i]<<"\n";
}



}
