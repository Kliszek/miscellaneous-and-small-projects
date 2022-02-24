#include <iostream>
#include <fstream>

using namespace std;


int klucz[50]={3,2,5,4,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


string zamien(string s, int a, int b)
{
    string w="";
    for(int i=0; i<s.size(); i++)
    {
        if(i==a) w+=s[b];
        else if(i==b) w+=s[a];
        else w+=s[i];
    }
    return w;
}

string szyfruj(string s, int dlugKlucz)
{
    //string w=s;
    for(int i=0; i<s.size(); i++)
    {
        s=zamien(s, i, klucz[i%dlugKlucz]-1);
    }
    return s;
}

void zad1()
{
    ifstream fin;
    fin.open("szyfr1.txt");
    string slowa[6];
    for(int i=0; i<6; i++) fin>>slowa[i];
    for(int i=0; i<50; i++) fin>>klucz[i];
    fin.close();

    for(int i=0; i<6; i++) cout<<szyfruj(slowa[i],50)<<"\n";
}

void zad2()
{
    ifstream fin;
    fin.open("szyfr2.txt");
    string slowo;
    fin>>slowo;
    for(int i=0; i<15; i++) fin>>klucz[i];
    fin.close();

    cout<<szyfruj(slowo,15)<<"\n";
}

string odszyfruj(string s, int dlugKlucz)
{
    //string w=s;
    for(int i=s.size()-1; i>=0; i--)
    {
        s=zamien(s, i, klucz[i%dlugKlucz]-1);
    }
    return s;
}


void zad3()
{
    ifstream fin;
    fin.open("szyfr3.txt");
    string slowo;
    fin>>slowo;
    fin.close();
    klucz[0]=6;
    klucz[1]=2;
    klucz[2]=4;
    klucz[3]=1;
    klucz[4]=5;
    klucz[5]=3;
    cout<<odszyfruj(slowo,6);


}



int main()
{
    //cout<<odszyfruj("KAAYTRNFOIM", 5)<<"\n\n";
    cout<<"Zadanie 1\n";
    zad1();
    cout<<"\nZadanie 2\n";
    zad2();
    cout<<"\nZadanie 3\n";
    zad3();
    cout<<"\n";
}
