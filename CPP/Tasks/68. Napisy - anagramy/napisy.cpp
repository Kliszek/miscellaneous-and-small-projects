#include <iostream>
#include <fstream>

using namespace std;


pair <string, string> napisy[1000];

void wczytaj()
{
    ifstream fin;
    fin.open("dane_napisy.txt");
    for(int i=0; i<1000; i++)
    {
        fin>>napisy[i].first;
        fin>>napisy[i].second;
    }
}

bool czyJednolity(string s)
{
    for(int i=1; i<s.size(); i++)
    {
        if(s[i]!=s[0]) return false;
    }
    return true;
}

bool czyAnagramy(string s1, string s2)
{
    if(s1.size()!=s2.size()) return false;
    int lit[10]={0};
    for(int i=0; i<s1.size(); i++)
    {
        lit[s1[i]-'A']++;
        lit[s2[i]-'A']--;
    }
    for(int i=0; i<10; i++)
    {
        if(lit[i]!=0) return false;
    }

    return true;
}

void zad1()
{
    int jednolitych=0;
    for(int i=0; i<1000; i++)
    {
        if(czyJednolity(napisy[i].first) && napisy[i].first==napisy[i].second) jednolitych++;
    }

    cout<<"Jednolitych anagramow: "<<jednolitych;
}

void zad2()
{
    int anagramow=0;

    for(int i=0; i<1000; i++)
    {
        if(czyAnagramy(napisy[i].first, napisy[i].second)) anagramow++;
    }
    cout<<"Anagramow: "<<anagramow;
}

void zad3()
{
    int najw=0;

    string aktNapis;
    for(int i=0; i<1000; i++)
    {
        aktNapis=napisy[i].first;

        int an=0; //ile ten wyraz ma anagramow w pliku

        for(int j=0; j<1000; j++)
        {
            if(czyAnagramy(napisy[j].first, aktNapis)) an++;
            if(czyAnagramy(napisy[j].second, aktNapis)) an++;
        }
        if(an>najw) najw=an;
        //------------------------
        aktNapis=napisy[i].second;

        an=0;

        for(int j=0; j<1000; j++)
        {
            if(czyAnagramy(napisy[j].first, aktNapis)) an++;
            if(czyAnagramy(napisy[j].second, aktNapis)) an++;
        }
        if(an>najw) najw=an;
    }
    cout<<"Najwieksza taka liczba wynosi: "<<najw;
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
