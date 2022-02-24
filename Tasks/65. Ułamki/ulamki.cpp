#include <iostream>
#include <fstream>

using namespace std;


pair <int,int> ulamki[1000];

void wczytaj()
{
    ifstream fin;
    fin.open("dane_ulamki.txt");
    for(int i=0; i<1000; i++)
    {
        fin>>ulamki[i].first;
        fin>>ulamki[i].second;
    }
    fin.close();
}

int NWD(int a, int b)
{
    if(a==b) return b;
    if(a>b) return NWD(a-b,b);
    else return NWD(b-a,a);
}

void zad1()
{
    pair <int,int> najmUl=ulamki[0];
    double najm=ulamki[0].first*1.0/ulamki[0].second;
    for(int i=0; i<1000; i++)
    {
        if(ulamki[i].first*1.0/ulamki[i].second < najm)
        {
            najm=ulamki[i].first*1.0/ulamki[i].second;
            najmUl=ulamki[i];
        }
    }
    cout<<"Najmniejszy ulamek: "<<najmUl.first<<" "<<najmUl.second;
}

void zad2()
{
    int nieskracalnych=0;
    for(int i=0; i<1000; i++)
    {
        if(NWD(ulamki[i].first, ulamki[i].second) == 1)
        {
            nieskracalnych++;
        }
    }
    cout<<"Nieskracalnych: "<<nieskracalnych;
}

void zad3()
{
    int suma=0;
    for(int i=0; i<1000; i++)
    {
        suma+=ulamki[i].first/NWD(ulamki[i].first, ulamki[i].second);
    }
    cout<<"Suma wszystkich licznikow po skroceniu ulamkow: "<<suma;
}

void zad4()
{
    long suma=0;
    for(int i=0; i<1000; i++)
    {
        suma+=ulamki[i].first*((2*2*3*3*5*5*7*7*13)/ulamki[i].second);
    }
    cout<<"Suma wszystkich licznikow po dodaniu ulamkow: "<<suma;
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
