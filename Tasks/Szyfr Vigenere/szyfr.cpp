#include <iostream>
#include <fstream>
#include <string>



using namespace std;



fstream cim1 ("dokad.txt");
fstream cim2 ("szyfr.txt");
ofstream cou ("wyniki.txt");


string tekst1;
string tekst2;
string klucz2;
string klucz="LUBIMYCZYTAC";
int wskaznik=0;
string zs="";

void zad1()
{
    int powt=0;
    cou<<"1.\n";
//    string zs="";

    for(int i=0; i<tekst1.size(); i++)
    {
        if(tekst1[i]<65 || tekst1[i]>90) zs+=tekst1[i];

        else
        {
            int znak=klucz[wskaznik]+tekst1[i]-130;
            znak=znak%26;
            znak+=65;
            //cout<<(char)znak;
            zs+=((char)znak);

            wskaznik++;
            if(wskaznik>=klucz.size()) {wskaznik=0; powt++;}
        }

    }
    cou<<tekst1.size()<<"\n"<<powt<<"\n"<<zs;

}

string zs2="";
void zad2()
{
    wskaznik=0;
    cou<<"\n2.\n";
//    string zs="";
    for(int i=0; i<tekst2.size(); i++)
    {
        if(tekst2[i]<65 || tekst2[i]>90) zs2+=tekst2[i];

        else
        {
            int znak=tekst2[i]-klucz2[wskaznik];
            znak+=26;
            znak=znak%26;
            znak+=65;
            //cout<<(char)znak;
            zs2+=((char)znak);

            wskaznik++;
            if(wskaznik>=klucz2.size()) wskaznik=0;
        }

    }
    cou<<zs2;
    //cout<<"\n\n\n\n"<<zs2;

}



void zad3()
{
    cou<<"\n3.\n";
    int lit=0;
    for(int i=0; i<tekst2.size(); i++)
    {
        if(tekst2[i]<65 || tekst2[i]>90) continue;
        lit++;
    }
    cou<<lit;

    int tab[26];
    for(int i=0; i<26; i++) tab[i]=0;

    for(int i=0; i<tekst2.size(); i++)
    {
        if(tekst2[i]<65 || tekst2[i]>90) continue;

        tab[tekst2[i]-65]++;

    }
    for(int i=0; i<26; i++)
    {
        cou<<"\n"<<(char)(65+i)<<": "<<tab[i];
    }



    double aa = 0;
    for(int i=0; i<26; i++)
    {
        aa+=tab[i]*(tab[i]-1);
    }
    double bb=lit*(lit-1);
    cou<<fixed;
    cou.precision(2);
    double tt=aa/bb;
    double wyn=0.0285/(tt-0.0385);
    cout<<aa<<endl<<bb<<endl<<tt<<endl<<wyn;
    cou<<"\n\n"<<wyn<<"\n";
    cou<<klucz2.size();
}

int main()
{
    getline(cim1, tekst1);
    getline(cim2, tekst2);
    getline(cim2, klucz2);

    zad1();
    zad2();
    zad3();

    //cout<<tekst;





}
