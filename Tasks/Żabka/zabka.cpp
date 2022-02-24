#include <iostream>

using namespace std;

int n, s, mSkok;



pair <int, int> tab[1002];
int odleglosci[1002];


int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n>>s>>mSkok;


    for(int i=0; i<n; i++)
    {
        cin>>tab[i].first;
        cin>>tab[i].second;
    }

    pair<int,int> o = tab[s-1];
    for(int i=0; i<n; i++)
    {
        tab[i].first -= o.first;
        tab[i].second -= o.second;
    }


    int najw=0;
    int ind=0;
    for(int i=0; i<n; i++)
    {
        odleglosci[i] = tab[i].first*tab[i].first+tab[i].second*tab[i].second;
        if(odleglosci[i]>najw)
            {
                najw=odleglosci[i];
                ind=i;
            }
    }



cout<<"\n\n";
    for(int i=0; i<n; i++)
    {
        cout<<tab[i].first<<" ";
        cout<<tab[i].second<<"\n";
    }
}
