#include <iostream>
#include <vector>
#include <queue>

//próbowa³em, nie zd¹¿y³em, ale wysy³am :(
using namespace std;


vector <int> drzewo[5002];

int mrowek;
int mrowki[1002];
//bool mrowki[5002];

int biedronek;
int biedronki[502];

int odl[5002];

int n, t1, t2;

queue <int> K;

bool czyMrowka(int wierzch)
{
    for(int i=0; i<mrowek; i++) if(mrowki[i]==w) return i;
}


int main()
{
    cin>>n;

    for(int i=0; i<5002; i++) odl[i]= -1;
    //int da=0;
    //for(int i=0; i<5002; i++) {if(mrowkiI[da]==i){ mrowki[i]=1; da++;} else mrowki[i]=0;}

    for(int i=0; i<n-1; i++)
    {
        cin>>t1;
        cin>>t2;
        drzewo[t1].push_back(t2);
        drzewo[t2].push_back(t1);
    }

    cin>>mrowek;

    for(int i=0; i<mrowek; i++)
    {
        cin>>mrowki[i];
    }

    cin>>biedronek;

    for(int i=0; i<biedronek; i++)
    {
        cin>>biedrinki[i];
    }



        for(int i=0; i<drzewo[ biedronki[0] ].size(); i++)
        {
            K.push(drzewo[ biedronki[1] ][i]);
        }
        odl[ biedronki[0] ] = 0;

        int w;

        while(!K.empty())
        {
            w=K.front();


        }


}
