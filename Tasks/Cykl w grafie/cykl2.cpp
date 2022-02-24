#include <iostream>
#include <vector>
#include <stack>

using namespace std;


vector <int> G[600002];
stack <int> stos;

int n,m;

bool odwiedzone[2n+1];


int DFS(int w, int ojciec)
{
    odwiedzone[w]=1;
    if(w>n)
    {odwiedzone[w-n]=1;stos.push(w-n);}
    else
    {odwiedzone[w+n]=1;stos.push(w+n);}

    for(int i=0; i<G[w].size(); i++)
    {
        if(odwiedzone[G[w][i]])
        {

        }


        else
        {

            DFS(G[w][i]);


        }
    }



}


int main()
{
    cin>>n>>m;

    int t1,t2;
    for(int i=0; i<m; i++)
    {
        cin>>t1>>t2;
        G[t1].push_back(t2+n);
        G[t2+n].push_back(t1);

        G[t2].push_back(t1+n);
        G[t1+n].push_back(t2);
    }

    for(int i=0; i=2n+1; i++)
    {
        odwiedzone[i]=0;
    }



}
