#include <iostream>
#include <fstream>

using namespace std;

string slowa[1876];

void wczytaj()
{
    ifstream fin;
    fin.open("tekst.txt");
    for(int i=0; i<1876; i++)
    {
        fin>>slowa[i];
    }
    fin.close();
}

void zad1()
{
    int wynik=0;
    for(int i=0; i<1876; i++)
    {
        for(int j=1; j<slowa[i].size(); j++)
        {
            if(slowa[i][j]==slowa[i][j-1]) {wynik++; break;}
        }
    }
    cout<<"Takich slow jest "<<wynik;
}

void zad2()
{
    int liter[26]={0};
    int wszystkichLiter=0;
    for(int i=0; i<1876; i++)
    {
        for(int j=0; j<slowa[i].size(); j++)
        {
            wszystkichLiter++;
            liter[ slowa[i][j]-'A' ]++;
        }
    }

    double procent;
    cout.precision(2);
    for(int i=0; i<26; i++)
    {
        procent=liter[i]*100.0/wszystkichLiter;
        cout<<fixed<<char(65+i)<<": "<<liter[i]<<" ("<<procent<<"%)\n";
    }
}

bool czySpolgloska(char c)
{
    if(c>'A' && c<='Z' && c!='E' && c!='I' && c!='O' && c!='U' && c!='Y') return true;
    return false;
}

void zad3()
{
    int najd=0;
    int aktDlug=0;
    for(int i=0; i<1876; i++)
    {
        aktDlug=0;
        for(int j=0; j<slowa[i].size(); j++)
        {
            if(czySpolgloska(slowa[i][j])) aktDlug++;
            else aktDlug=0;
            if(aktDlug>najd) najd=aktDlug;
        }
    }
    //NAJPIERW OBLICZANIE NAJDLUZSZEGO :P
    int slowZPodciagiem=0;
    string pierwszeSlowo="";

    for(int i=0; i<1876; i++)
    {
        aktDlug=0;
        for(int j=0; j<slowa[i].size(); j++)
        {
            if(czySpolgloska(slowa[i][j])) aktDlug++;
            else aktDlug=0;
            if(aktDlug==najd) {slowZPodciagiem++; if(pierwszeSlowo=="") pierwszeSlowo=slowa[i]; break;}
        }
    }

    cout<<"Najdluzsze takie podslowo ma dlugosc "<<najd;
    cout<<"\nJest "<<slowZPodciagiem<<" slow z taka dlugoscia podciagu";
    cout<<"\nPierwsze z nich to: "<<pierwszeSlowo;
}

int main()
{
    wczytaj();
    cout<<"Zadanie 1\n";
    zad1();
    cout<<"\n\nZadanie 2\n";
    zad2();
    cout<<"\nZadanie 3\n";
    zad3();
    cout<<"\n";
}
