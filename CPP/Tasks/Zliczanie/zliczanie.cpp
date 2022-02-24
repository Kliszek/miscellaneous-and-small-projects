#include <iostream>
#include <algorithm>

using namespace std;




int wiezniow;

int main()
{
    cin>>wiezniow;

    pair<int, pair<int, int> >tab[wiezniow];

    for(int i=0; i<wiezniow; i++)
    {
        cin>>tab[i].second.second;
        cin>>tab[i].first;
        tab[i].second.first=i+1;

    }

    sort(tab, tab+wiezniow);

    for(int i=0; i<wiezniow; i++)
    {
        cout<<tab[i].second.second<<"\n";


    }
}
