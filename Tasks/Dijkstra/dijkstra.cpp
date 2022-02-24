#include <iostream>
#include <queue>
#include <vector>

#define INF 1000000002
#define f first
#define waga second

using namespace std;

std::priority_queue<pair<int,int>, std::vector<pair<int,int> >, std::greater<pair<int, int> > > kolejka;
vector <pair<int,int> > graf[200003];


int k,w;
int droga[100002];



void dijkstra(int s)
{

    kolejka.pop();


    for(int i=0; i<graf[s].size(); i++)
    {

        if(droga[ graf[s][i].f ] > droga[ s ] + graf[s][i].waga)
        {
            droga[ graf[s][i].f ] = droga[ s ] + graf[s][i].waga;

            kolejka.push(make_pair( droga[ graf[s][i].f ], graf[s][i].f ));
        }

    }

}

int main()
{
    cin>>w>>k;


    int t1,t2,t3;
    for(int i=0; i<k; i++)
    {
        cin>>t1>>t2>>t3;
        //graf[t1].push_back(make_pair(t2,t3));
        graf[t2].push_back(make_pair(t1,t3));
    }


    for(int i=0; i<=w; i++)
    {
        droga[i]=INF;
    }

    droga[1]=0;

    kolejka.push(make_pair(0,1));

    while(!kolejka.empty())
    {
        //if(droga[ kolejka.top().second ] < kolejka.top().first) kolejka.pop();
        //else dijkstra(kolejka.top().second);
        dijkstra(kolejka.top().second);
    }


    for(int i=1; i<=w; i++)
    {
        if(droga[i]==INF)   cout<<"+oo\n";
        else                cout<<droga[i]<<"\n";
    }
}
