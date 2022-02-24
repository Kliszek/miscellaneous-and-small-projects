#include <iostream>
#include <fstream>
#define wspX first
#define wspY second.first
#define promien second.second

using namespace std;

pair<double, pair<double,double> > okregi[2000];

void wczytaj()
{
    ifstream fin;
    fin.open("okregi.txt");
    for(int i=0; i<2000; i++)
    {
        fin>>okregi[i].wspX;
        fin>>okregi[i].wspY;
        fin>>okregi[i].promien;
    }
    fin.close();
}

double wartBez(double x)
{
    if(x<0) return -x;
    return x;
}

void zad1()
{
    int cwiartki[5]={0};
    for(int i=0; i<2000; i++)
    {
        if(okregi[i].promien>=wartBez(okregi[i].wspX) || okregi[i].promien>=wartBez(okregi[i].wspY))
        {
            cwiartki[4]++;
            continue;
        }
        else if(okregi[i].wspX>0 && okregi[i].wspY>0) {cwiartki[0]++; continue;}
        else if(okregi[i].wspX<0 && okregi[i].wspY>0) {cwiartki[1]++; continue;}
        else if(okregi[i].wspX<0 && okregi[i].wspY<0) {cwiartki[2]++; continue;}
        else if(okregi[i].wspX>0 && okregi[i].wspY<0) {cwiartki[3]++; continue;}
    }

    for(int i=0; i<4; i++) cout<<"Okregow w "<<i+1<<". cwiartce: "<<cwiartki[i]<<"\n";
    cout<<"Okregow przecinajacych osie: "<<cwiartki[4];
}

void zad2()
{
    int lustrzanychPar=0;

    for(int i=0; i<2000; i++)
    {
        for(int j=0; j<2000; j++)
        {
            if(i==j) continue;
            if(okregi[i].promien != okregi[j].promien) continue;

            if(okregi[i].wspX==-okregi[j].wspX && okregi[i].wspY==okregi[j].wspY) lustrzanychPar++;
            else if(okregi[i].wspX==okregi[j].wspX && okregi[i].wspY==-okregi[j].wspY) lustrzanychPar++;
        }
    }
    lustrzanychPar/=2;
    cout<<"Lustrzanych par: "<<lustrzanychPar;
}

void zad3()
{
    int prostopadlychPar=0;

    for(int i=0; i<2000; i++)
    {
        for(int j=0; j<2000; j++)
        {
            if(i==j) continue;
            if(okregi[i].promien != okregi[j].promien) continue;

            if(okregi[i].wspX==-okregi[j].wspY && okregi[i].wspY==okregi[j].wspX) prostopadlychPar++;
            else if(okregi[i].wspX==okregi[j].wspY && okregi[i].wspY==-okregi[j].wspX) prostopadlychPar++;
        }
    }
    prostopadlychPar/=2;
    cout<<"Prostopadlych par: "<<prostopadlychPar;
}

bool majaPunktWspolny(int a, int b)
{
    double odlKw=(okregi[a].wspX-okregi[b].wspX)*(okregi[a].wspX-okregi[b].wspX) + (okregi[a].wspY-okregi[b].wspY)*(okregi[a].wspY-okregi[b].wspY);
    //r1+r2>odl r1-r2<odl
    if((okregi[a].promien+okregi[b].promien)*(okregi[a].promien+okregi[b].promien)>odlKw && (okregi[a].promien-okregi[b].promien)*(okregi[a].promien-okregi[b].promien)<odlKw)
        return true;
    return false;

}

void zad4()
{
    int najdCiag=0;
    int ciag=1;
    for(int i=1; i<1000; i++)
    {
        if(majaPunktWspolny(i,i-1)) ciag++;
        else {cout<<"Dlugosc kolejnego lancucha: "<<ciag<<"\n"; ciag=1;}
        if(ciag>najdCiag) najdCiag=ciag;
        if(i==999) cout<<"Dlugosc ostatniego lancucha: "<<ciag;
    }
    cout<<"\nNajdluzszy lancuch: "<<najdCiag;
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
    cout<<"\n\nZadanie 4\n";
    zad4();
    cout<<"\n";
}
