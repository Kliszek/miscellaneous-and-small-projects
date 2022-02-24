#include <iostream>
#include <fstream>

using namespace std;

pair <string, string> napisy[200];

void wczytaj()
{
    ifstream fin;
    fin.open("napisy.txt");
    for(int i=0; i<200; i++)
    {
        fin>>napisy[i].first>>napisy[i].second;
    }
    fin.close();
}

void zad1()
{
    int pierwszyIndeks=-1;
    int wynik=0;
    for(int i=0; i<200; i++)
    {
        if(napisy[i].first.size()/napisy[i].second.size()>=3 || napisy[i].second.size()/napisy[i].first.size()>=3)
        {
            wynik++;
            if(pierwszyIndeks==-1) pierwszyIndeks=i;
        }
    }
    cout<<"Takich par jest "<<wynik;
    cout<<"\nPierwsza z nich to: "<<napisy[pierwszyIndeks].first<<" "<<napisy[pierwszyIndeks].second;
}

void zad2()
{
    for(int i=0; i<200; i++)
    {
        if(napisy[i].first.size()>=napisy[i].second.size()) continue;

        bool daSie=true;

        for(int j=0; j<napisy[i].first.size(); j++)
        {
            if(napisy[i].first[j]!=napisy[i].second[j]) {daSie=false; break;}
        }

        if(daSie)
        {
            cout<<napisy[i].first<<" "<<napisy[i].second<<" ";
            for(int j=napisy[i].first.size(); j<napisy[i].second.size(); j++)
            {
                cout<<napisy[i].second[j];
            }
            cout<<"\n";
        }
    }
}

void zad3()
{
    int najw=0;
    for(int i=0; i<200; i++)
    {
        int dlug=0;
        while(napisy[i].first[napisy[i].first.size()-dlug-1] == napisy[i].second[napisy[i].second.size()-dlug-1])
            dlug++;
        if(dlug>najw) najw=dlug;
    }
    //oddzielnie sprawdzanie najdluzszych koncowek i oddzielne wypisywanie ich, bo czemu nie
    cout<<"Najdluzsza koncowka ma dlugosc "<<najw<<"\n";
    for(int i=0; i<200; i++)
    {
        int dlug=0;
        while(napisy[i].first[napisy[i].first.size()-dlug-1] == napisy[i].second[napisy[i].second.size()-dlug-1])
            dlug++;
        if(dlug==najw) cout<<napisy[i].first<<" "<<napisy[i].second<<"\n";
    }
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
}
