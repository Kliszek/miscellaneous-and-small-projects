#include <iostream>
#include <fstream>
//#include <ofstream>


using namespace std;


fstream cim ("dane.txt");

string slowa[200][2];

string rozwiazania[200];


int zad2=0;
int zad3=0;

string znajdzC(int n)
{
    if(slowa[n][0]==slowa[n][1]) return slowa[n][0]; //czy slowa sa takie same


    bool zawierasie=true;
    for(int i=0; i<=slowa[n][0].size()-slowa[n][1].size(); i++)
    {
        zawierasie=true;
        for(int j=0; j<slowa[n][1].size(); j++)
        {
            if(slowa[n][0][i+j]!=slowa[n][1][j]) {zawierasie=false; break;}
        }
        if(zawierasie) {zad2++; return (slowa[n][0] /*+ " B zawiera sie w A"*/);}
    }

    //if(slowa[i][0].find(slowa[i][1]) != string::npos) return slowa[i][0]; //slowo 1 zawiera slowo 2

    int pocz=0;
    int kon=0;

    while(true)
    {
        bool ok=true;
        for(int k=0; k<=pocz; k++)
        {
            if(slowa[n][0][slowa[n][0].size()-1-pocz+k]!=slowa[n][1][k]) {ok=false; break;}
        }
        if(!ok) break;
        pocz++;
    }

        //(slowa[n][0][slowa[n][0].size()-1-pocz]==slowa[n][1][pocz]) pocz++;

    while(true)
    {
        bool ok=true;
        for(int k=0; k<=kon; k++)
        {
            if(slowa[n][1][slowa[n][1].size()-1-kon+k]!=slowa[n][0][k]) {ok=false; break;}
        }
        if(!ok) break;
        kon++;
    }

    //while(slowa[n][1][slowa[n][1].size()-1-kon]==slowa[n][0][kon]) kon++;

    string rozw="";

    if(pocz==0 && kon==0) zad3++;

    if(pocz>kon)
    {
        for(int j=0; j<slowa[n][0].size()-pocz; j++)
        {
            rozw+=slowa[n][0][j];
        }
        rozw+=slowa[n][1];
        //rozw+=" polaczone A B ";
        //rozw+=std::to_string(pocz);
        return rozw;
    }

    else
    {
        for(int j=0; j<slowa[n][1].size()-kon; j++)
        {
            rozw+=slowa[n][1][j];
        }
        rozw+=slowa[n][0];
        //rozw+=" polaczone B A ";
        //rozw+=to_string(kon);
        return rozw;
    }


}


void zad1()
{
    int wynik=0;
    for(int i=0; i<200; i++)
    {
        bool ok=true;
        for(int j=0; j<slowa[i][0].size(); j++)
        {
            if(slowa[i][0][j]!=slowa[i][0][slowa[i][0].size()-1-j]) {ok=false; break;}
        }
        if(ok) wynik++;
    }

    for(int i=0; i<200; i++)
    {
        bool ok=true;
        for(int j=0; j<slowa[i][1].size(); j++)
        {
            if(slowa[i][1][j]!=slowa[i][1][slowa[i][1].size()-1-j]) {ok=false; break;}
        }
        if(ok) wynik++;
    }
    cout<<"Zad 1.\n"<<wynik<<"\n";
}


int main()
{

    for(int i=0; i<200; i++)
    {
        cim>>slowa[i][0];
        cim>>slowa[i][1];
    }


    zad1();

    ofstream cou ("slowa.txt");

    for(int i=0; i<200; i++) cou<<znajdzC(i)<<"\n";

    cout<<"\nZad 2.\n"<<zad2<<"\n\nZad 3.\n"<<zad3;


    /*
    for(int i=0; i<200; i++)
    {
        cout<<slowa[i][0]<<" "<<slowa[i][1]<<"    "<<znajdzC(i)<<"\n";
    }
    */



}
