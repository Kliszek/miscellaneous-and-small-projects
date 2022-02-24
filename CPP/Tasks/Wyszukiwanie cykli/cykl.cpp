#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


int w,k;

vector <int> graf[300002];
stack <int> stos;
bool odwiedzone[300002];



bool CyklDFS(int q)
{

    odwiedzone[q]=true;
    int poprzednik=stos.top();
    stos.push(q);



    for(int i=0; i<graf[q].size(); i++)
    {

        if(!odwiedzone[ graf[q][i] ])
        {

            if(CyklDFS(graf[q][i])) return true;

            continue;
        }

        if(odwiedzone[ graf[q][i] ] && graf[q][i]!=poprzednik)
        {
            stos.push(graf[q][i]);
            return true;
        }
    }

    stos.pop();
    return false;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin>>w>>k;

    int t1,t2;
    for(int i=0; i<k; i++)
    {
        cin>>t1>>t2;
        graf[t1].push_back(t2);
        graf[t2].push_back(t1);
    }



    for(int i=0; i<300002; i++) odwiedzone[i]=false;



    stos.push(0);


    bool CYKL = CyklDFS(1);

    for(int i=0; i<w; i++)
    {

    }

    if(!CYKL)
    {
        cout<<"NIE\n";
        return 0;
    }

    else
    {
        cout<<"TAK\n";
        int wezel = stos.top();



        queue <int> kol;

        do
        {
            kol.push(stos.top());
            stos.pop();
        }
        while(stos.top()!=wezel);

        cout<<kol.size()<<"\n";

        while(!kol.empty())
        {
            cout<<kol.front()<<" ";
            kol.pop();
        }

    }


}
