#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


long long odcinki[500];

void wczytaj()
{
    ifstream fin;
    fin.open("dane_trojkaty.txt");
    for(int i=0; i<500; i++) fin>>odcinki[i];
    fin.close();
}

bool czyProstokatny(long long a, long long b, long long c)
{
    if(a>b && b>c)
    {
        if(a*a==b*b+c*c) return true;
    }
    if(b>a && a>c)
    {
        if(b*b==a*a+c*c) return true;
    }
    else
        if(c*c==a*a+b*b) return true;

    return false;
}

void zad1()
{
    long long bokiT[3];
    for(int i=2; i<500; i++)
    {
        bokiT[0]=odcinki[i-2];
        bokiT[1]=odcinki[i-1];
        bokiT[2]=odcinki[i];
        sort(bokiT, bokiT+3);

        if(bokiT[0]*bokiT[0]+bokiT[1]*bokiT[1]==bokiT[2]*bokiT[2])
        {
            cout<<odcinki[i-2]<<" "<<odcinki[i-1]<<" "<<odcinki[i]<<"\n";
        }
    }
}

bool czyTrojkat(long long a, long long b, long long c)
{
    if(a+b>c && a+c>b && b+c>a) return true;
    return false;
}

void zad2()
{
    long long tab2[500];
    for(int i=0; i<500; i++) tab2[i]=odcinki[i];

    sort(tab2, tab2+500);

    int wsp=0;
    while(!czyTrojkat(tab2[499-wsp], tab2[498-wsp], tab2[497-wsp]))
    {
        wsp++;
    }
    cout<<"Najwiekszy obwod wynosi: "<<tab2[499-wsp]+tab2[498-wsp]+tab2[497-wsp];
}
//*/

void zad3()
{
    long long trojkatow=0;
    for(int x=0; x<500; x++) for(int y=0; y<500; y++) for(int z=0; z<500; z++)
    {
        if(x==y || y==z || z==x) continue;
        if(czyTrojkat(odcinki[x],odcinki[y],odcinki[z])) trojkatow++;
    }
    trojkatow/=6;
    cout<<"Mozna utworzyc "<<trojkatow<<" nieprzystajacych trojkatow";
}
int main()
{
    wczytaj();
    cout<<"Zadanie 1\n";
    zad1();
    cout<<"\n\nZadanie 2\n";
    zad2();
    cout<<"\n\nZadanie 3\n";
    zad3();
    cout<<"\n";

}
