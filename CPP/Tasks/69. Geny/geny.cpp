#include <iostream>
#include <fstream>

using namespace std;

string genotypy[1000];

void wczytaj()
{
    ifstream fin;
    fin.open("dane_geny.txt");
    for(int i=0; i<1000; i++)
    {
        fin>>genotypy[i];
    }
    fin.close();
}

void zad1()
{
    int gatunki[500]={0};
    for(int i=0; i<1000; i++)
    {
        gatunki[genotypy[i].size()-1]++;
    }
    int najw=0, gatunkow=0;

    for(int i=0; i<500; i++)
    {
        if(gatunki[i]>0) gatunkow++;
        if(gatunki[i]>najw) najw=gatunki[i];
    }
    cout<<"Na planecie jest "<<gatunkow<<" gatunkow\n";
    cout<<"Najwieksza liczba osobnikow reprezentujacych ten sam gatunek to "<<najw;
}

string czescKodujaca(string s)
{
    string w="", t="";
    bool czyGen=false;
    for(int i=1; i<s.size();i++)
    {
        if(czyGen) t+=s[i];
        if(s[i]=='A' && s[i-1]=='A')
        {
            t+="AA";
            czyGen=true;
        }
        if(s[i]=='B' && s[i-1]=='B' && czyGen)
        {
            w+=t;
            czyGen=false;
            t="";
        }
    }
    return w;
}

bool czyZawieraMutacje(string s)
{
    for(int i=0; i<s.size()-4; i++)
    {
        if(s[i]=='B')
        {
            if(s[i+1]=='C' && s[i+2]=='D' && s[i+3]=='D' && s[i+4]=='C') return true;
        }

    }
    return false;
}

void zad2()
{
    int zmutowanych=0;
    for(int i=0; i<1000; i++)
    {
        if(czyZawieraMutacje(czescKodujaca(genotypy[i]))) zmutowanych++;
    }
    cout<<"Osobnikow z mutacja: "<<zmutowanych;
}

void zad3()
{
    int najw=0;
    int najd=0;
    string t="";
    for(int j=0; j<1000; j++)
    {
        t="";
        int genow=0;
        bool czyGen=false;
        for(int i=1; i<genotypy[j].size();i++)
        {
            if(czyGen) t+=genotypy[j][i];
            if(genotypy[j][i]=='A' && genotypy[j][i-1]=='A' && !czyGen)
            {
                t+="AA";
                czyGen=true;
            }
            if(genotypy[j][i]=='B' && genotypy[j][i-1]=='B' && czyGen)
            {
                genow++;
                czyGen=false;
                if(t.size()>najd) najd=t.size();
                t="";
            }
        }
        if(genow>najw) najw=genow;
    }
    cout<<"Najwiecej genow u jednego osobnika: "<<najw;
    cout<<"\nNajdluzszy gen: "<<najd;
}

string odwroc(string s)
{
    string w="";
    for(int i=s.size()-1; i>=0; i--)
    {
        w+=s[i];
    }
    return w;
}

void zad4()
{
    int odpornych=0, silnieOdpornych=0;
    for(int i=0; i<1000; i++)
    {
        if(genotypy[i]==odwroc(genotypy[i]))
        {
            silnieOdpornych++; //JESLI JEST SILNIE ODPORNY TO JEST TEZ ODPORNY
            odpornych++;
            continue;
        }
        if(czescKodujaca(genotypy[i])==czescKodujaca(odwroc(genotypy[i])))
        {
            odpornych++;
            continue;
        }
    }

    cout<<"Odpornych: "<<odpornych;
    cout<<"\nSilnie odpornych: "<<silnieOdpornych;
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
