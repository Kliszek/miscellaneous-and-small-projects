#include <iostream>
#include <fstream>

//WALIC, JEST ZBYT ZLE, ZA BARDZO KOMBINOWALEM
using namespace std;

string obrazki[200][21];


void wczytaj()
{
    fstream fin;
    fin.open("dane_obrazki.txt");
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<21; j++)
        {
            fin>>obrazki[i][j];
        }
    }

}

int zadanie_a()
{
    int rewersow=0;
    for(int i=0; i<200; i++)
    {
        int bialych=0,czarnych=0;
        for(int x=0;x<20;x++)
        {
            for(int y=0;y<20;y++)
            {
                if(obrazki[i][x][y]=='1') czarnych++;
                else bialych++;
            }
        }
        if(czarnych>bialych) rewersow++;
    }
    return rewersow;
}

int zadanie_b(string &pierwszy)
{
    int rekurencyjnych=0;
    for(int i=0; i<200; i++)
    {
        bool czyRek=true;
        for(int y=0;y<10;y++)
        {
            if(!czyRek) break;
            for(int x=0;x<10;x++)
            {
                if(obrazki[i][y][x]!=obrazki[i][y][x+10] || obrazki[i][y][x]!=obrazki[i][y+10][x] || obrazki[i][y][x]!=obrazki[i][y+10][x+10])
                {
                    czyRek=false;
                    break;
                }
            }
        }
        if(czyRek)
        {
            rekurencyjnych++;
            if(rekurencyjnych==1) //zapisywanie pierwszego rekurencyjnego
            {
                for(int y=0;y<20;y++)
                {
                    for(int x=0;x<20;x++)
                    {
                        pierwszy+=obrazki[i][y][x];
                    }
                }
            }
        }
    }

    return rekurencyjnych;
}

void poprawnoscObrazka(int indeks, int &X, int &Y, int &B)
{
    int zlaKolumna=-1, zlyWiersz=-1;
    bool parzystosc=0;
    int bledne=0;

    for(int y=0;y<20;y++)
    {
        for(int x=0;x<20;x++)
        {
            if(obrazki[indeks][y][x]=='1') parzystosc=(!parzystosc);
        }
        if((obrazki[indeks][y][20]=='0') == parzystosc)
        {
            if(zlaKolumna==-1) zlaKolumna=y+1;
            else {X=-2; Y=-2; zlyWiersz=-2; zlaKolumna=-2; bledne++;}
        }
    }

    parzystosc=0;
    for(int x=0;x<20;x++)
    {
        for(int y=0;y<20;y++)
        {
            if(obrazki[indeks][y][x]=='1') parzystosc=(!parzystosc);
        }
        if((obrazki[indeks][20][x]=='0') == parzystosc)
        {
            if(zlyWiersz==-1) zlyWiersz=x+1;
            else {X=-2; Y=-2; zlyWiersz=-2; zlaKolumna=-2; bledne++;}
        }
    }
    X=zlyWiersz; Y=zlaKolumna; B=bledne;
    return;
}

void zadanie_c(int &P, int &N, int &NN, int &NB)
{
    int najw=0;
    int popr=0,napr=0,nienapr=0;
    for(int i=0; i<200; i++)
    {
        int x,y,bledow;
        poprawnoscObrazka(i,x,y,bledow);
        if(bledow>najw) najw=bledow;
        if(x==-1 && y==-1) popr++;
        else if(x==-2) nienapr++;
        else napr++;
    }
    //return odp;
    P=popr;N=napr;NN=nienapr;NB=najw;
}

void zadanie_d()
{
    //string w="a";
    for(int i=0; i<200; i++)
    {
        int x,y,b;
        poprawnoscObrazka(i,x,y,b);
        if(y==-1 && x!=-1) cout<<i+1<<": 21 "<<y<<"\n";
        else if(y!=-1 && x==-1) cout<<i+1<<": "<<y<<" 21\n";
        else if(x>-1 && y>-1) cout<<i+1<<": "<<y<<" "<<x<<"\n";
    }
    return;
}

int main()
{
    wczytaj();
    cout<<"Zadanie 1\n";
    cout<<zadanie_a();
    cout<<"\n\nZadanie 2\n";
    string pierwszyRek="";
    cout<<zadanie_b(pierwszyRek);
    cout<<"\n\n";
    for(int i=0; i<400; i++) {cout<<pierwszyRek[i]; if((i+1)%20==0)cout<<"\n";}
    int p,n,nn,nb;
    zadanie_c(p,n,nn,nb);
    cout<<"Poprawnych obrazkow: "<<p<<"\nNaprawialnych: "<<n<<"\nNienaprawialnych: "<<nn<<"\nNajwiecej bledow: "<<nb;
    cout<<"\n\n";zadanie_d();

}
