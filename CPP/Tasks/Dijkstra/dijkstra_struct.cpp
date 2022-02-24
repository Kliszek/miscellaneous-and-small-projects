#include <iostream>
#include <vector>
#include <queue>
#define wierz first
#define waga second
#define mp make_pair
#define INF 1000000002


using namespace std;


struct Wierzcholek
{
    vector <pair<int,int> > sasiedzi;
    int poprzednik;
};



Wierzcholek graf[200003];

std::priority_queue<pair<int,int>, std::vector<pair<int,int> >, std::greater<pair<int,int> > > kolejka;

int w,k;

int droga[100002];


void dijkstra(int s)
{
    kolejka.pop();

    for(int i=0; i<graf[s].sasiedzi.size(); i++)
    {
        if(droga[ graf[s].sasiedzi[i].wierz ] > droga[s] + graf[s].sasiedzi[i].waga)
        {
            droga[ graf[s].sasiedzi[i].wierz ] = droga[s] + graf[s].sasiedzi[i].waga;
            kolejka.push(mp(droga[ graf[s].sasiedzi[i].wierz ], graf[s].sasiedzi[i].wierz));
            graf[graf[s].sasiedzi[i].wierz].poprzednik=s;
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
        graf[t2].sasiedzi.push_back(mp(t1,t3));
    }

    for(int i=1; i<=w; i++)
    {
        droga[i]=INF;
    }
    kolejka.push(mp(0,1));

    while(!kolejka.empty())
    {
        dijkstra(kolejka.top().second);
    }


    for(int i=1; i<=w; i++)
    {
        cout<<droga[i]<<"\n";
    }
}
