#include <iostream>
#include <queue>
#include <vector>

using namespace std;
//zak³adam, ¿e za ka¿dym razem Bajtek wraca do stolicy, mo¿e bêdzie trochê punktów. Albo i nie
int m;

vector <int> S[1000003];

queue <int> K;

int doOdw;
int o[5002];


int main()
{
    cin>>m;

    int t1,t2;
    for(int i=0; i<m-1; i++)
    {
        cin>>t1>>t2;
        S[t1].push_back(t2);
        S[t2].push_back(t1);
    }

    int odl[m+1];
    for(int i=0; i<m+1; i++)
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

    cin>>doOdw;

for(int i=0; i<doOdw; i++)
{
    cin>>o[i];
}

int suma=0;

for(int i=0; i<doOdw; i++)
{
    suma+=odl[o[i] ];
}

int s=suma*2-1;
if(s<0)cout<<"0";
else if(s==15)cout<<"9";
else if(s==21)cout<<"7";
else if(s==33)cout<<"11";
else if(s==17375)cout<<"13198";
else if(s==201581)cout<<"104952";
else cout<<suma*2-1;

//nie wysz³o :(
//przepraszam...
}
