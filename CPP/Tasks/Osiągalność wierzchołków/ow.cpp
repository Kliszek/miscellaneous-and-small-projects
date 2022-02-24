#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool K=false;

int w,k;

vector <int> S[100003];

bool odwiedzone[100003];

int ojciec=0;

bool cykl=false;
int poczatek;
stack <int> wwc;

void DFS(int s)
{


    odwiedzone[s]=1;

    for(int i=0; i<S[s].size(); i++)
    {
        if(odwiedzone[S[s][i]]==1)
        {
            if(S[s][i]!=ojciec)
            {
                cykl=true;
                poczatek=S[s][i];
                wwc.push(S[s][i]);
            }
        }

        if(odwiedzone[S[s][i]]!=1)
        {
            ojciec=s;
            DFS(S[s][i]);


            if(K)return;
            if(cykl)
            {
                if(S[s][i]==poczatek)
                {
                    K=true;
                    return;
                }
                else
                {
                    wwc.push(S[s][i]);
                    return;
                }
            }
        }
    }



}


int main()
{

    cin>>w>>k;

    int a,b;
    for(int i=0; i<k; i++)
    {
        cin>>a>>b;
        S[b].push_back(a);
        S[a].push_back(b);
    }
     DFS(1);

     if(!cykl)
        cout<<"NIE\n";
     else
     {
         cout<<"TAK\n";
         cout<<wwc.size()<<"\n";
         while(wwc.size()>0)
         {
             cout<<wwc.top()<<" ";
             wwc.pop();
         }

     }
     //for(int i=1; i<=w; i++)
     //{

     //}




}
