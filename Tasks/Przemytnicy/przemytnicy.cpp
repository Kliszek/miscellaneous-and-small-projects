#include <iostream>
#include <vector>
#include <queue>
#define INF 2147483647

using namespace std;




int n,m;

int drogi1[5002];
int drogi2[5002];

vector <pair<int,int> > przemiany1[100002];
vector <pair<int,int> > przemiany2[100002];
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > kolejka;




int dijkstra1(int s)
{
    kolejka.pop();

    for(int i=0; i<przemiany1[s].size(); i++)
    {
        if(drogi1[ przemiany1[s][i].first ] > drogi1[s] + przemiany1[s][i].second)
        {
            drogi1[ przemiany1[s][i].first ] = drogi1[s] + przemiany1[s][i].second;

            kolejka.push(make_pair( drogi1[ przemiany1[s][i].first ], przemiany1[s][i].first ));
        }
    }
}


int dijkstra2(int s)
{
    kolejka.pop();

    for(int i=0; i<przemiany2[s].size(); i++)
    {
        if(drogi2[ przemiany2[s][i].first ] > drogi2[s] + przemiany2[s][i].second)
        {
            drogi2[ przemiany2[s][i].first ] = drogi2[s] + przemiany2[s][i].second;

            kolejka.push(make_pair( drogi2[ przemiany2[s][i].first ], przemiany2[s][i].first ));
        }
    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;



    int ceny[n+1];

    ceny[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>ceny[i];
    }

    if(n==1) //jeœli znaj¹ tylko z³oto, to dalej bêd¹ b³êdy... :P
    {
        cout<<ceny[1]/2;
        return 0;
    }

    cin>>m;
    int t1,t2,t3;
    for(int i=1; i<=m; i++)
    {
        cin>>t1>>t2>>t3;
        przemiany1[t1].push_back(make_pair(t2,t3));
        przemiany2[t2].push_back(make_pair(t1,t3));//przemiany od ka¿dego metalu do z³ota
    }


    for(int i=0; i<5002; i++)
    {
        drogi1[i]=INF;
        drogi2[i]=INF;
    }

    drogi1[1]=0;
    kolejka.push(make_pair(0,1));

    while(!kolejka.empty())
    {
        dijkstra1(kolejka.top().second);
    }

    kolejka = priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > >();
    //resetuje kolejkê

    drogi2[1]=0;
    kolejka.push(make_pair(0,1));

    while(!kolejka.empty())
    {
        dijkstra2(kolejka.top().second);
    }


    priority_queue <int, vector<int>, greater<int> > wynik;

    for(int i=0; i<n; i++)
    {
        if(drogi1[i]==INF || drogi2[i]==INF) continue;
        wynik.push(drogi1[i]+drogi2[i]+(ceny[i]/2));
    }
    cout<<wynik.top();
}
