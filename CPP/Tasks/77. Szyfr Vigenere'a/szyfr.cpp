#include <iostream>
#include <fstream>

using namespace std;

string szyfruj(string s, string klucz)
{
    //powtorzen=0;
    string w="";
    //int spacji=0;
    int indeksKlucza=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]<65 || s[i]>90) {w+=s[i]; continue;}

        int nr=s[i]-'A'+klucz[indeksKlucza];
        if(nr>90) nr-=26;
        w+=char(nr);
        indeksKlucza++;
        if(indeksKlucza>=klucz.size())
        {
            indeksKlucza=0;
            //cout<<"A ";
            //powtorzen++;
            //cout<<powtorzen<<" ";
        }
    }
    //cout<<powtorzen;
    return w;
}


void zad1()
{
    ifstream fin;
    fin.open("dokad.txt");
    string wiersz;
    getline(fin, wiersz);
    fin.close();
    //--------------------------------------------
    string w="";
    string klucz="LUBIMYCZYTAC";
    int powtorzen=1;
    int indeksKlucza=0;
    for(int i=0; i<wiersz.size(); i++)
    {
        if(wiersz[i]<65 || wiersz[i]>90) {w+=wiersz[i]; continue;}

        int nr=wiersz[i]-'A'+klucz[indeksKlucza];
        if(nr>90) nr-=26;
        w+=char(nr);
        indeksKlucza++;
        if(indeksKlucza>=klucz.size())
        {
            indeksKlucza=0;
            //cout<<"A ";
            powtorzen++;
            //cout<<powtorzen<<" ";
        }
    }
    //--------------------------------------------

    cout<<"Powtorzen: "<<powtorzen<<"\n"<<w;
}



void zad2()
{
    ifstream fin;
    fin.open("szyfr.txt");
    string wiersz;
    getline(fin, wiersz);
    string klucz;
    getline(fin, klucz);
    fin.close();
    //--------------------------------------------
    string w="";
    int indeksKlucza=0;
    for(int i=0; i<wiersz.size(); i++)
    {
        if(wiersz[i]<65 || wiersz[i]>90) {w+=wiersz[i]; continue;}

        int nr=wiersz[i]+'A'-klucz[indeksKlucza];
        if(nr<65) nr+=26;
        w+=char(nr);
        indeksKlucza++;
        if(indeksKlucza>=klucz.size())
        {
            indeksKlucza=0;
            //cout<<"A ";
            //cout<<powtorzen<<" ";
        }
    }
    //--------------------------------------------

    cout<<w;
}

void zad3()
{
    ifstream fin;
    fin.open("szyfr.txt");
    string wiersz;
    getline(fin, wiersz);
    string klucz;
    getline(fin, klucz);
    fin.close();

    int liter[26]={0};
    int wszystkichLiter=0;
    for(int i=0; i<wiersz.size(); i++)
    {
        if(wiersz[i]>=65 && wiersz[i]<=90) {liter[wiersz[i]-'A']++; wszystkichLiter++;}
    }
    for(int i=0; i<26; i++)
    {
        cout<<char('A'+i)<<": "<<liter[i]<<"\n";
    }

    double zmiennaK=0;
    for(int i=0; i<26; i++)
    {
        zmiennaK+=liter[i]*(liter[i]-1);
    }
    zmiennaK/=wszystkichLiter*1.0*(wszystkichLiter-1);
    double zmiennaD=0.0285/(zmiennaK-0.0385);

    cout.precision(2);
    cout<<fixed<<"Szacunkowa dlugosc klucza: "<<zmiennaD<<"\nRzeczywista dlugosc: "<<klucz.size();
}

int main()
{
    //cout<<szyfruj("JEST OK", "EWA");
    cout<<"Zadanie 1\n";
    zad1();
    cout<<"\n\nZadanie 2\n";
    zad2();
    cout<<"\n\nZadanie 3\n";
    zad3();
    cout<<"\n";
}
