#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#define A_x first
#define A_y second.first.first
#define B_x second.first.second
#define B_y second.second.first
#define C_x second.second.second.first
#define C_y second.second.second.second


using namespace std;

pair<int,pair<pair<int,int>,pair<int,pair<int, int> > > > wierzcholki[100];
pair<int,pair<pair<int,int>,pair<int,pair<int, int> > > > wierzcholkiTR[100];

void wczytaj()
{
    ifstream fin, finTR;
    fin.open("wspolrzedne.txt");
    finTR.open("wspolrzedneTR.txt");
    for(int i=0; i<100; i++)
    {
        fin>>wierzcholki[i].A_x;
        fin>>wierzcholki[i].A_y;
        fin>>wierzcholki[i].B_x;
        fin>>wierzcholki[i].B_y;
        fin>>wierzcholki[i].C_x;
        fin>>wierzcholki[i].C_y;
    }
    for(int i=0; i<100; i++)
    {
        finTR>>wierzcholkiTR[i].A_x;
        finTR>>wierzcholkiTR[i].A_y;
        finTR>>wierzcholkiTR[i].B_x;
        finTR>>wierzcholkiTR[i].B_y;
        finTR>>wierzcholkiTR[i].C_x;
        finTR>>wierzcholkiTR[i].C_y;
    }
    fin.close();
    finTR.close();
}

void zad1()
{
    int wierszy=0;
    for(int i=0; i<100; i++)
    {
        if(wierzcholki[i].A_x>0 && wierzcholki[i].A_y>0 && wierzcholki[i].B_x>0 && wierzcholki[i].B_y>0 && wierzcholki[i].C_x>0 && wierzcholki[i].C_y>0)
            wierszy++;
    }
    cout<<"Takich wierszy jest: "<<wierszy;
}

double wartBez(double a)
{
    if(a<0) return -a;
    return a;
}

bool czyWspolliniowe(int indeks)
{
    pair<int,int> wektorAB = make_pair(wierzcholki[indeks].B_x-wierzcholki[indeks].A_x, wierzcholki[indeks].B_y-wierzcholki[indeks].A_y);
    pair<int,int> wektorBC = make_pair(wierzcholki[indeks].C_x-wierzcholki[indeks].B_x, wierzcholki[indeks].C_y-wierzcholki[indeks].B_y);
    double wspX=1.0*wektorAB.first/wektorBC.first;
    double wspY=1.0*wektorAB.second/wektorBC.second;

    if(wartBez(wspX-wspY)<0.00001) return true;
    return false;
}

void zad2()
{
    int wspolliniowych=0;
    for(int i=0; i<100; i++)
    {
        if(czyWspolliniowe(i)) wspolliniowych++;
    }
    cout<<"Punktow wspolliniowych: "<<wspolliniowych;
}

double odlegloscPunktow(int x1, int y1, int x2, int y2)
{
    double odlKw=(x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0;
    return sqrt(odlKw);
}

void zad3()
{
    double najd=0;
    int indNajd;
    double boki[3];
    for(int i=0; i<100; i++)
    {
        boki[0]=odlegloscPunktow(wierzcholkiTR[i].A_x, wierzcholkiTR[i].A_y, wierzcholkiTR[i].B_x, wierzcholkiTR[i].B_y);
        boki[1]=odlegloscPunktow(wierzcholkiTR[i].C_x, wierzcholkiTR[i].C_y, wierzcholkiTR[i].B_x, wierzcholkiTR[i].B_y);
        boki[2]=odlegloscPunktow(wierzcholkiTR[i].A_x, wierzcholkiTR[i].A_y, wierzcholkiTR[i].C_x, wierzcholkiTR[i].C_y);

        double obwod=boki[0]+boki[1]+boki[2];

        if(obwod>najd) {najd=obwod; indNajd=i;}
    }
    cout.precision(2);
    cout<<"Wspolrzedne:\tA: ("<<wierzcholkiTR[indNajd].A_x<<", "<<wierzcholkiTR[indNajd].A_y<<")\tB: ("<<wierzcholkiTR[indNajd].B_x<<", "<<wierzcholkiTR[indNajd].B_y<<")\tC: ("<<wierzcholkiTR[indNajd].C_x<<", "<<wierzcholkiTR[indNajd].C_y<<")\n";
    cout<<fixed<<"Najdluzszy obwod trojkata: "<<najd;
}

bool czyProstakatny(double boki[3])
{
    //double boki[3]={a,b,c};
    sort(boki, boki+3);
    //cout<<boki[0]<<" "<<boki[1]<<" "<<boki[2]<<"\n";
    if(wartBez(boki[2]*boki[2]-boki[0]*boki[0]-boki[1]*boki[1])<0.0001) return true;
    return false;
}

void zad4()
{
    double boki[3];
    int prostokatnych=0;

    for(int i=0; i<100; i++)
    {
        boki[0]=odlegloscPunktow(wierzcholkiTR[i].A_x, wierzcholkiTR[i].A_y, wierzcholkiTR[i].B_x, wierzcholkiTR[i].B_y);
        boki[1]=odlegloscPunktow(wierzcholkiTR[i].C_x, wierzcholkiTR[i].C_y, wierzcholkiTR[i].B_x, wierzcholkiTR[i].B_y);
        boki[2]=odlegloscPunktow(wierzcholkiTR[i].A_x, wierzcholkiTR[i].A_y, wierzcholkiTR[i].C_x, wierzcholkiTR[i].C_y);

        if(czyProstakatny(boki)) prostokatnych++;
    }
    cout<<"Trojkatow prostakatnych: "<<prostokatnych;

}

void zad5()
{
    for(int i=0; i<100; i++)
    {
        pair<int,int> wektorBA = make_pair(wierzcholkiTR[i].A_x-wierzcholkiTR[i].B_x, wierzcholkiTR[i].A_y-wierzcholkiTR[i].B_y);
        pair<int,int> wektorBC = make_pair(wierzcholkiTR[i].C_x-wierzcholkiTR[i].B_x, wierzcholkiTR[i].C_y-wierzcholkiTR[i].B_y);
        pair <int,int> wektorBD = make_pair(wektorBA.first+wektorBC.first, wektorBA.second+wektorBC.second);

        pair <int, int> wierzD = make_pair(wierzcholkiTR[i].B_x+wektorBD.first, wierzcholkiTR[i].B_y+wektorBD.second);

        if(wierzD.first == wierzD.second)
        {
            cout<<"A: ("<<wierzcholkiTR[i].A_x<<", "<<wierzcholkiTR[i].A_y<<")\t";
            cout<<"B: ("<<wierzcholkiTR[i].B_x<<", "<<wierzcholkiTR[i].B_y<<")\t";
            cout<<"C: ("<<wierzcholkiTR[i].C_x<<", "<<wierzcholkiTR[i].C_y<<")\t";
            cout<<"D: ("<<wierzD.first<<", "<<wierzD.second<<")\n";
        }
    }
}


int main()
{
    //double bbb[3]={12.0,5.0,13.0};
    //cout<<czyProstakatny(bbb)<<"\n\n";
    //cout<<odlegloscPunktow(0,0,3,4)<<"\n\n";
    wczytaj();
    cout<<"Zadanie 1\n";
    zad1();
    cout<<"\n\nZadanie 2\n";
    zad2();
    cout<<"\n\nZadanie 3\n";
    zad3();
    cout<<"\n\nZadanie 4\n";
    zad4();
    cout<<"\n\nZadanie 5\n";
    zad5();
    cout<<"\n";
}
