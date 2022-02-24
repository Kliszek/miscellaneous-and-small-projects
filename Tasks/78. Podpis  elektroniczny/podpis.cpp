#include <iostream>
#include <fstream>

using namespace std;

string wiadomosci[11];
int podpisy[11][8];



string skrot(string wiad, bool zadanie1)
{
    //a)
    int S[8]={'A', 'L', 'G', 'O', 'R', 'Y', 'T', 'M'};

    //b
    while(wiad.size()%8!=0) wiad+='.';

    //ZADANIE 1
    if(zadanie1) cout<<"Liczba znakow po uzupelnieniu wiadomosci: "<<wiad.size()<<"\nWartosci liczbowe:\n";

    //c
    for(int i=0; i<wiad.size()-1; i+=8) for(int j=0; j<8; j++)
    {
        S[j]=(S[j]+wiad[i+j])%128;
    }

    //ZADANIE 1
    if(zadanie1) for(int i=0; i<8; i++) cout<<S[i]<<" ";

    //d
    string wynik="";
    for(int i=0; i<8; i++)
    {
        wynik+=char('A'+S[i]%26);
    }

    return wynik;
}

string A(int d, int n, int podpis[8])
{
    string wynik="";
    for(int i=0; i<8; i++)
    {
        wynik+=char(podpis[i]*d%n);
    }
    return wynik;
}

void wczytaj()
{
    ifstream fin;
    fin.open("wiadomosci.txt");
    for(int i=0; i<11; i++) {getline(fin, wiadomosci[i]);}
    fin.close();
    fin.open("podpisy.txt");
    for(int i=0; i<11; i++) for(int j=0; j<8; j++) {fin>>podpisy[i][j];}
    fin.close();
}

void zad1()
{
    cout<<"\n"<<skrot(wiadomosci[0], true);
}

void zad2()
{
    for(int i=0; i<11; i++)
    {
        cout<<A(3, 200, podpisy[i])<<"\n";
    }
}

void zad3()
{
    for(int i=0; i<11; i++)
    {
        if(skrot(wiadomosci[i], false)==A(3, 200, podpisy[i])) cout<<i+1<<" ";
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
    cout<<"\n";

}
