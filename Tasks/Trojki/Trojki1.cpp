#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;


fstream cim ("trojki.txt");
ofstream cou ("wyniki_trojki.txt");


int tab [1000][3];
int suma=0;
int t;


bool czyPierwsza(int aaa)
{
    for(int i=2; i*i<=aaa; i++)
    {
        if(aaa%i==0) return false;
    }
    return true;
}


void zad1()
{
    cou<<1<<"\n";
    for(int i=0; i<1000; i++)
    {
        suma=0;
        for(int j=0; j<2; j++)
        {
            t=tab[i][j];
            while(t>=10)
            {
                suma+= t%10;
                t/=10;
            }
            suma+=t;
        }
        if(suma==tab[i][2])
        {
            cou<<tab[i][0]<<" "<<tab[i][1]<<" "<<tab[i][2]<<"\n";
        }

    }
}



void zad2()
{
    cou<<2<<"\n";
    for(int i=0; i<1000; i++)
    {
        if(czyPierwsza(tab[i][0]) && czyPierwsza(tab[i][1]))
        {
            if(tab[i][0]*tab[i][1]==tab[i][2])
            {
                cou<<tab[i][0]<<" "<<tab[i][1]<<" "<<tab[i][2]<<"\n";
            }
        }
    }
}



void zad3()
{
    cou<<3<<"\n";
    bool bb=false;
    int tt[3];
    for(int i=0; i<1000; i++)
    {
        tt[0]=tab[i][0];
        tt[1]=tab[i][1];
        tt[2]=tab[i][2];

        sort(tt, tt+3);

        tt[0]*=tt[0];
        tt[1]*=tt[1];
        tt[2]*=tt[2];

        if(tt[0]+tt[1]==tt[2])
        {
            if(bb)
            {
                cou<<tab[i-1][0]<<" "<<tab[i-1][1]<<" "<<tab[i-1][2]<<"\n";
                cou<<tab[i][0]<<" "<<tab[i][1]<<" "<<tab[i][2]<<"\n";
            }
            bb=true;
        }
        else
            bb=false;
    }
}


void zad4()
{
    cou<<4<<"\n";
    int tt[3];
    int n=0,naj=0;
    int s=0;

    for(int i=0; i<1000; i++)
    {
        tt[0]=tab[i][0];
        tt[1]=tab[i][1];
        tt[2]=tab[i][2];

        sort(tt, tt+3);

        if(tt[0]+tt[1]>tt[2])
        {
            n++;
            if(n>naj)naj=n;
            s++;
        }
        else n=0;

    }
    cou<<s<<"\n"<<naj;
}

int main()
{

    for(int i=0; i<1000; i++)
    {
        for(int j=0; j<3; j++) cim>>tab[i][j];
    }

    zad1();
    zad2();
    zad3();
    zad4();
}
