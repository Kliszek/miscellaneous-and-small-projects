#include <iostream>
#include <algorithm>

using namespace std;



int m,n;


int main()
{

    cin>>m>>n;

    int x[m];
    for(int i=0; i<m-1; i++)
    {
        cin>>x[i];
    }
    x[m-1]=0;
    sort(x, x+m);

    int y[n];
    for(int i=0; i<n-1; i++)
    {
        cin>>y[i];
    }
    y[n-1]=0;
    sort(y, y+n);


    int a=m-1; //ostatni indeks do x
    int b=n-1; //ostatni indeks do y

    int wynik=0;

    int mnx = 1;
    int mny = 1; //mnozniki

    while(a>0 && b>0)
    {
        int ta=x[a];
        int tb=y[b];

        if(ta>=tb && tb>0)
        {
            a--;
            mny++;
            wynik+=ta*mnx;
        }

        if(tb>=ta && ta>0)
        {
            b--;
            mnx++;
            wynik+=tb*mny;
        }

    }

    if(a==0)
    {
        while(b>0) {wynik+=y[b]*mny; b--;}
    }

    if(b==0)
    {
        while(a>0) {wynik+=x[a]*mnx; a--;}
    }
    cout<<wynik;

}
