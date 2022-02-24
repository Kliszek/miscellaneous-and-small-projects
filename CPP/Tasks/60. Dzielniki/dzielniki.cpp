#include <iostream>
#include <fstream>

using namespace std;



int liczby[200];


void zadanie_a()
{
    int w=0, ost1=1, ost2=1;
    for(int i=0; i<200; i++)
    {
        if(liczby[i]<1000)
        {
            ost1=ost2;
            ost2=liczby[i];
            w++;
        }
    }
    cout<<"Liczb mniejszych od 1000: "<<w;
    cout<<"\nDwie ostatnie to: "<<ost1<<" i "<<ost2<<"\n";
}

void zadanie_b()
{
    for(int i=0; i<200; i++)
    {
        int a=liczby[i];
        int dzielnikow=0;
        for(int j=1; j<=liczby[i]; j++)
        {
            if(liczby[i]%j==0) dzielnikow++;
        }
        if(dzielnikow==18)
        {
            cout<<liczby[i]<<"\n  ";
            for(int j=1; j<=liczby[i]; j++)
            {
                if(liczby[i]%j==0) cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
}

int NWD(int a, int b)
{
    if(a==b) return b;
    if(a>b) return NWD(a-b, b);
    else return NWD(b-a, a);
}

void zadanie_c()
{
    int najw=0;
    for(int i=0; i<200; i++)
    {
        bool wzgld=true;
        for(int j=0; j<200; j++)
        {
            if(i==j) continue;
            if(NWD(liczby[i],liczby[j])!=1) {wzgld=false; break;}
        }
        if(wzgld && liczby[i]>najw) najw=liczby[i];
    }
    cout<<najw;
}

void wczytaj()
{
    ifstream fin;
    fin.open("liczby.txt");
    for(int i=0; i<200; i++)
    {
        fin>>liczby[i];
    }
    fin.close();
}

int main()
{
    wczytaj();
    zadanie_a();
    zadanie_b();
    zadanie_c();

}
