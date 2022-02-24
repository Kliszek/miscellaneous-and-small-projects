#include <iostream>
#include <math.h>
#include <vector>


//#define int long long
using namespace std;


int pieter, maks;

int drzewo[131075];
int D[131080][41];


//#undef int
int main()
//#define int long long
{
    ios_base::sync_with_stdio(false);
    cin>>pieter>>maks;

    int parkart = pow(2, pieter)-1;


    //drzewo[0]=2000003;



    int t;
    for(int i=1; i<=parkart; i++)
    {
        cin>>t;
        cin>>drzewo[i];
        drzewo[i]+=t;
    }

   //cout<<"Par kart: "<<parkart<<"\n\n";

   //cout<<"Wszystkie karty: \n";

    //cout<<"DEB  "<<drzewo[7]<<"\n\n";

    for(int i=1; i<=parkart; i++)
    {
        D[i][0]=0;
        D[i][2]=drzewo[i];
        //cout<<"  karta nr "<<i<<"\n";//<<"DEBUG  "<<D[i].size()<<"\n";;
    }

    //cout<<"\n\nDalsze karty:\n";//<<"DEBUG  "<<D[7].size()<<"\n";
    int a;
    for(int i=parkart/2; i>0; i--)
    {
        a=drzewo[i];
        //cout<<"  karta nr "<<i<<"\n";
        //cout<<"    analizuje:\n    karte nr "<<i*2<<" i "<<i*2+1<<"\n";
        for(int j=0; j<maks; j++)
        {
            D[i][j+2] = D[i*2][j].first+a;
        }


        for(int j=0; j<D[i*2].size(); j++)
        {
            //D[i].push_back(make_pair(D[i*2][j].first+a, D[i*2][j].second+2));

            for(int q=0; q<D[i*2+1].size(); q++)
            {
            D[(D[i*2][j].second+D[i*2+1][q].second+2)/2-1]=make_pair(  D[i*2][j].first + D[i*2+1][q].first + a, D[i*2][j].second+D[i*2+1][q].second+2);
            }
        }


        for(int j=0; j<maks; j++)
        {
            D[i][j+2]=D[i*2+1][j];//(D[i*2+1][j].second+2)/2-1]=make_pair(D[i*2+1][j].first+a, D[i*2+1][j].second+2);
        }
        //D[i].push_back(drzewo[i]);

    }

//cout<<"JYTFBYTFB YT Y\n";
    cout<<"\n\n";
    int najw=0;
    for(int i=0; i<D[1].size(); i++)
    {
        if(D[1][i].second<=maks) if(D[1][i].first>najw) najw=D[1][i].first;
    cout<<D[1][i].first<<", ilosc kart: "<<D[1][i].second<<"\n";
    }
    cout<<"\n";
    cout<<najw;
}

