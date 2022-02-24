#include <iostream>
#include <vector>
#include <stack>
#define INF 2000000

using namespace std;

stack <int> ro;

int w,k,zap;


vector <pair<int,int> > graf[1002];
int drogi[1002];
int poprzednicy[1002];



void bf()
{
    for(int i=1; i<=w-1; i++)
    {


        for(int j=1; j<=w; j++)
        {
            for(int m=0; m<graf[j].size(); m++)
            {
                if(drogi[graf[j][m].first] > drogi[j]+graf[j][m].second)
                {
                    drogi[graf[j][m].first] = drogi[j]+graf[j][m].second;
                    poprzednicy[j] = graf[j][m].first;
                }

            }
        }


    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>w>>k>>zap;


    int t1,t2,t3;
    for(int i=0; i<k; i++)
    {
        cin>>t1>>t2>>t3;
        graf[t1].push_back(make_pair(t2,t3));
    }


    for(int j=0; j<zap; j++)
    {
        cin>>t1;
        //stack tetes;
        //tetes+=toString(t1);
        //cout<<"DEBUG "<<tetes<<" DEBUG\n";

        for(int i=1; i<=w; i++)
        {
            drogi[i]=INF;
            poprzednicy[i]=-1;
        }

        drogi[t1]=0;

        bf();

        cin>>t2;


        if(drogi[t2]==INF)
            cout<<"NIE\n";
        else
        {
            cout<<drogi[t2]<<" ";
            //int aa=1;

            while(t2!=t1)
            {
                ro.push(t2);
                //ro+=" ";
                t2=poprzednicy[t2];
                //aa++;
            }
            //ro+=t1;
            cout<<ro.size()+1<<" "<<t1<<" ";

            while(!ro.empty())
            {
                cout<<ro.top()<<" ";
                ro.pop();
            }
            cout<<"\n";
        }

    }

}

