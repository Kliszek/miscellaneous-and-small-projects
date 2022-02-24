#include <iostream>





using namespace std;


int n;
int a=0;
bool k=1;
int polana=1;
bool bb[41];


int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        bb[i]=1;
    }
    pair<int, int> tab[n-1];

    int t1,t2;

    for(int i=0; i<n-1; i++)
    {
        cin>>t1>>t2;
        tab[i] = make_pair(t1,t2);
    }

    while(polana!=n)
    {
        if(!bb[polana-1])
        {
            polana=tab[polana-1].first;
        }
        else
        {
            polana=tab[polana-1].second;
        }
            //cout<<"polana zmieniona";

        bb[polana-1] = !bb[polana-1];

        a++;
    //cout<<polana<<"\n";
    }

    a++;


    //if(polana==1) cout<<"nigdy";
    cout<<a;
}
