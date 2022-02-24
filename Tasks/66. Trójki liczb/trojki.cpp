#include <iostream>
#include <fstream>

#define jeden first
#define dwa second.first
#define trzy second.second

using namespace std;


pair <int, pair<int,int> > trojki[1000];

void wczytaj()
{
    ifstream fin;
    fin.open("trojki.txt");
    for(int i=0; i<1000; i++)
    {
        fin>>trojki[i].jeden;
        fin>>trojki[i].dwa;
        fin>>trojki[i].trzy;
    }
}

bool czyPierwsza(int l)
{
    if(l<2) return false;
    if(l==2) return true;
    for(int i=3; i*i<=l; i=i+2)
    {
        if(l%i==0) return false;
    }
    return true;
}

void zad1()
{
    //int wynik=0;
    for(int i=0; i<1000; i++)
    {
        int suma=0;
        int t=trojki[i].jeden;
        while(t>0)
        {
            suma+=t%10;
            t/=10;
        }
        t=trojki[i].dwa;
        while(t>0)
        {
            suma+=t%10;
            t/=10;
        }
        if(suma==trojki[i].trzy) cout<<trojki[i].jeden<<" "<<trojki[i].dwa<<" "<<trojki[i].trzy<<"\n";
    }
    //cout<<"Takich trojek jest "<<wynik;
}

void zad2()
{
    //int wynik=0;
    for(int i=0; i<1000; i++)
    {
        if(czyPierwsza(trojki[i].jeden) && czyPierwsza(trojki[i].dwa) && trojki[i].jeden*trojki[i].dwa==trojki[i].trzy)
            cout<<trojki[i].jeden<<" "<<trojki[i].dwa<<" "<<trojki[i].trzy<<"\n";
    }
    //cout<<"Takich trojek jest "<<wynik;
}

void zad3()
{
    //int wynik=0;
    long long przeciwpr, przypr;
    for(int i=0; i<1000; i++)
    {
        if(trojki[i].jeden>trojki[i].dwa && trojki[i].jeden>trojki[i].trzy)
        {
            przeciwpr=trojki[i].jeden*trojki[i].jeden;
            przypr=trojki[i].dwa*trojki[i].dwa+trojki[i].trzy*trojki[i].trzy;
        }
        else if(trojki[i].dwa>trojki[i].trzy && trojki[i].dwa>trojki[i].jeden)
        {
            przeciwpr=trojki[i].dwa*trojki[i].dwa;
            przypr=trojki[i].jeden*trojki[i].jeden+trojki[i].trzy*trojki[i].trzy;
        }
        else if(trojki[i].trzy>trojki[i].dwa && trojki[i].trzy>trojki[i].jeden)
        {
            przeciwpr=trojki[i].trzy*trojki[i].trzy;
            przypr=trojki[i].dwa*trojki[i].dwa+trojki[i].jeden*trojki[i].jeden;
        }

        if(przeciwpr==przypr) cout<<trojki[i].jeden<<" "<<trojki[i].dwa<<" "<<trojki[i].trzy<<"\n";
    }

    //cout<<"Takich trojek jest "<<wynik;
}

bool czyTrojkat(int i)
{
    if(trojki[i].jeden<trojki[i].dwa+trojki[i].trzy && trojki[i].dwa<trojki[i].jeden+trojki[i].trzy && trojki[i].trzy<trojki[i].dwa+trojki[i].jeden)
        return true;
    return false;
}

void zad4()
{
    int trojkatnych=0;
    int najdCiag=0;
    int ciag=0;
    for(int i=0; i<1000; i++)
    {
        if(czyTrojkat(i))
        {
            trojkatnych++;
            ciag++;
            if(ciag>najdCiag) najdCiag=ciag;
        }
        else
            ciag=0;
    }

    cout<<"Trojek trojkatnych: "<<trojkatnych<<"\nNajdluzszy ciag trojkatny: "<<najdCiag;
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
