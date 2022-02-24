#include <iostream>
#include <fstream>

using namespace std;

string slowa[805], probki[5][2];

void wczytaj()
{
    ifstream fin;
    fin.open("tekst.txt");
    for(int i=0; i<805; i++)
    {
        fin>>slowa[i];
    }
    fin.close();
    fin.open("probka.txt");
    for(int i=0; i<5; i++)
    {
        fin>>probki[i][0]>>probki[i][1];
    }
}

string szyfruj(string s, int A, int B)
{
    string w="";
    for(int i=0; i<s.size(); i++)
    {
        int wspolczynnik=(s[i]-'a')*A+B;
        wspolczynnik%=26;
        w+=char(wspolczynnik+'a');
    }
    return w;
}

void zad1()
{
    for(int i=0; i<805; i++)
    {
        if(slowa[i][0]=='d' && slowa[i][slowa[i].size()-1]=='d') cout<<slowa[i]<<"\n";
    }
}

void zad2()
{
    for(int i=0; i<805; i++)
    {
        if(slowa[i].size()>=10) cout<<szyfruj(slowa[i],5,2)<<"\n";
    }
}

void zad3()
{
    for(int i=0; i<5; i++)
    {
        int A=0, B=0;
        while(probki[i][1]!=szyfruj(probki[i][0],A,B))
        {
            B++;
            if(B>25) {A++; B=0;}
        }
        cout<<"Klucz szyfrujacy: ("<<A<<", "<<B<<")\tKlucz deszyfrujacy :(";
        A=0; B=0;
        while(probki[i][0]!=szyfruj(probki[i][1],A,B))
        {
            B++;
            if(B>25) {A++; B=0;}
        }
        cout<<A<<", "<<B<<")\n";
    }
}

int main()
{
    wczytaj();

    //cout<<szyfruj("u",9,15)<<"\n";
    cout<<"Zadanie 1\n";
    zad1();
    cout<<"\nZadanie 2\n";
    zad2();
    cout<<"\nZadanie 3\n";
    zad3();
    cout<<"\n";
}
