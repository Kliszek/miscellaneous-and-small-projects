#include <iostream>
#include <fstream>

using namespace std;

double wspolczynniki[5][4];


void wczytaj()
{
    ifstream fin;
    fin.open("funkcja.txt");
    for(int i=0; i<5; i++)
    {
        fin>>wspolczynniki[i][0];
        fin>>wspolczynniki[i][1];
        fin>>wspolczynniki[i][2];
        fin>>wspolczynniki[i][3];
    }
}


double funkcja(double x)
{
    int q;

    if(x>=0.0 && x<1.0) q=0;
    if(x>=1.0 && x<2.0) q=1;
    if(x>=2.0 && x<3.0) q=2;
    if(x>=3.0 && x<4.0) q=3;
    if(x>=4.0 && x<5.0) q=4;

    return wspolczynniki[q][0] + wspolczynniki[q][1]*x+wspolczynniki[q][2]*x*x+wspolczynniki[q][3]*x*x*x;
}

void zad1()
{
    cout.precision(5);
    cout<<fixed<<"Wartosc funkcji w 1.5 = "<<funkcja(1.5);
}

void zad2()
{
    double najw=0.0;
    double argument;

    for(double i=0.0; i<5.0; i+=0.001)
    {
        if(funkcja(i)>najw)
        {
            najw=funkcja(i);
            argument=i;
        }
    }
    cout<<"W podanym przedziale funkcja osiaga najwieksza wartosc rowna "<<najw<<" dla argumentu ";
    cout.precision(3);
    cout<<argument;
}

double znajdzMiescjeZerowe(double a, double b) //PO KIEGO SIUSIAKA NAPISALEM TA FUNKCJE TO JA NIE WIEM
{                                               //TO GOWNO NAWET NIE DZIALA, TYLKO NIE WIEM CZEMU
    double fA=funkcja(a),fB=funkcja(b);         //DOBRA NAPRAWILEM
    //if(fA*fB>0.0) cout<<"error";
    double fAB=funkcja(0.5*(a+b));

    double roznica=fA-fB;
    if(roznica<0.0) roznica*=-1.0;

    if(roznica<0.00001) return a;

    if(fA*fAB>0.0) //jeœli fA ma taki sam znak jak fAB
        return znajdzMiescjeZerowe(0.5*(a+b), b);   //TUTAJ DAWALEM WARTOSCI FUNKCJI ZAMIAST ARGUMENTOW
    else
        return znajdzMiescjeZerowe(a, 0.5*(a+b));

}
/*
void zad3()
{
    cout.precision(5);
    for(double i=0.0; i<5.0; i+=0.1)
    {
        if(funkcja(i)*funkcja(i+0.1)<0.0) cout<<"Miejsce zerowe: "<<znajdzMiescjeZerowe(i,i+0.1)<<"\n";
    }
}//*/

void zad3()
{
    cout.precision(5);
    for(double i=0.0; i<5.0; i+=0.000001) //naprawde duza dokladnosc na wszelki wypadek
    {
        if(funkcja(i)*funkcja(i+0.000001)<0.0) cout<<"Miejsce zerowe: "<<i<<"\n";
    }
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
