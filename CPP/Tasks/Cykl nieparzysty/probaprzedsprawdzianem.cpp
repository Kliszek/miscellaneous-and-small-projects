#include <iostream>
#include <vector>
#define skok 400000
#include <stack>
#include <queue>

using namespace std;



int w,k;
vector <int> graf[700004];
bool odwiedzone[700004];
stack <int> stos;


bool CyklDFS(int q)
{
    odwiedzone[q]=true;
    //int poprzednik=stos.top();
    stos.push(q);
    //cout<<"Wierzcholek "<<q<<"\n";


    for(int i=0; i<graf[q].size(); i++)
    {

        if((q<skok && odwiedzone[ graf[q][i]-skok ]) || (q>skok && odwiedzone[ graf[q][i]+skok ]))
        {
            stos.push(graf[q][i]);
            return true;
        }
        //cout<<"\tSasiad "<<graf[q][i]<<"\n";
        if(!odwiedzone[ graf[q][i] ])
        {

            if(CyklDFS(graf[q][i])) return true;

            continue;
        }




    }

    stos.pop();

    return false;
}



int main()
{
    cin>>w>>k;

    int t1,t2;
    for(int i=0; i<k; i++)
    {
        cin>>t1>>t2;
        graf[t1].push_back(t2+skok);
        graf[t2].push_back(t1+skok);
        graf[t1+skok].push_back(t2);
        graf[t2+skok].push_back(t1);
    }

    for(int i=0; i<700004; i++)
    {
        odwiedzone[i]=false;
    }

    stos.push(0);

    bool CYKL = CyklDFS(1);


    if(!CYKL) cout<<"NIE\n";

    else
    {
        cout<<"TAK\n";
        int wezel = stos.top();
        //cout<<"Wezel = "<<wezel<<"\n";
        //if(wezel>400000) wezel-=400000;
        //else wezel+=400000;



        queue <int> kol;


        while((stos.top() + 400000 != wezel) && (stos.top() - 400000 != wezel))
        {
            //cout<<stos.top()<<" ";
            kol.push(stos.top());
            stos.pop();
        }

        cout<<kol.size()<<"\n";

        //cout<<"Przod kolejki: "<<kol.front()<<"\n";

        while(!kol.empty())
        {
            if(kol.front()>400000)
                cout<<kol.front()-400000<<" ";
            else
                cout<<kol.front()<<" ";
            kol.pop();
        }

    }

}
