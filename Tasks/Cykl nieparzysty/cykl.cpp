#include <iostream>
#include <vector>
#include <stack>
#include <queue>


using namespace std;


int w,k;

vector <int> graf[1000000];
bool odwiedzone[1000000];
stack <int> stos;




bool CyklDFS(int q)
{
    //cout<<"Jestem w wierzcholku "<<q<<"\n";
    odwiedzone[q]=true;
    //int poprzednik = stos.top();
    stos.push(q);

    for(int i=0; i<graf[q].size(); i++)
    {
        //cout<<"\tSasiad "<<q<<": "<<graf[q][i]<<", \t\tq="<<q<<", i= "<<i <<"\n";
        if( (q<400000 && odwiedzone[ graf[q][i] - 400000]) || ( q>400000 && odwiedzone[ graf[q][i] + 400000 ]) )
        {
            stos.push(graf[q][i]);
            return true;
        }

        if(!odwiedzone[ graf[q][i] ])
        {
            //cout<<"\nWYWOLUJE CyklDFS(graf["<<q<<"]["<<i<<"]) = CyklDFS("<<graf[q][i]<<")\n\n";
            if(CyklDFS(graf[q][i])) return true;

            continue;

        }

    }
    stos.pop();
    //cout<<"\nZakonczylem, false\n\n";
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
        graf[t1].push_back(t2+400000);
        graf[t1+400000].push_back(t2);
        graf[t2].push_back(t1+400000);
        graf[t2+400000].push_back(t1);
    }

    /*for(int i=0; i<=w; i++)
    {
        cout<<"\nSasiedzi "<<i<<":\n";
        for(int j=0; j<graf[i].size(); j++)
        {
            cout<<"\t"<<graf[i][j]<<" ";
        }
    }cout<<"\n\n\n";*/
    //cout<<"BUG: "<<cout<<graf[3][2]<<"\n\n";

    for(int i=0; i<1000000; i++)
    {
        odwiedzone[i]=false;
    }

    stos.push(400000);

    bool CYKL = CyklDFS(1);

    if(!CYKL)
    {
        cout<<"NIE\n";
        return 0;
    }

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
