#include <iostream>
#include <queue>

using namespace std;



int n,m;
bool tab[100002];
bool tab2[100002];


bool super(int d)
{
    //cout<<"suma "<<d;
    int r=0;
    while(d>=10)
    {
        r+=d%10;
        d/=10;
    }
    r+=d;
    //cout<<" to "<<r<<"\n";
    if(tab[r]) return true;
    return false;
}


bool b(int d)
{


    int r=0;
    int t=1;

    cout<<"dla d="<<d;
    for(int i=0;i<32;i++)
    {
        if(d & t)
        {
            r++;
        }
        d >> 1;
    }
    cout<<" r="<<r<<"\n";
    if(tab[r]) return true;
    return false;
}




int main()
{
    cin>>n>>m;

    //bool tab[m+1];

    for(int i=0;i<=m;i++) {tab[i]=true; tab2[i]=true;}

    tab[0]=0; tab[1]=0; tab2[0]=0; tab2[1]=0;


    //PIERWSZE
    int d=2;
    while(true)
    {
        if(tab[d]==0)
        {
            d++;
            continue;
        }
        if(d*d>m) break;

        int f=2;
        while(d*f<=m)
        {
            tab[d*f]=0;
            tab2[d*f]=0;
            f++;
        }
        d++;
    }

    //SUPER
    for(int i=0; i<=m; i++)
    {
        if(tab[i])
        {
            if(!super(i))
            {
                tab2[i]=0;
            }
        }
    }


    //SUPER

    for(int i=0; i<=m; i++)
    {
        if(tab2[i])
        {
            if(!b(i))
            {
                tab2[i]=0;
            }
        }
    }



    for(int i=0; i<=m; i++)
    {
        if(tab2[i]) cout<<i<<" ";
    }

}
