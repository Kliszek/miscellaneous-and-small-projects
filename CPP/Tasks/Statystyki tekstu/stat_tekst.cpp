#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

fstream cim ("tekst.txt");
ofstream cou ("wyniki.txt");


string tab[1876];


void zad1()
{
    cou<<1<<"\n";
    char currentChar='0';
    int suma=0;

    for(int i=0; i<1876; i++)
    {
        currentChar='0';
        for(int j=0; j<tab[i].size(); j++)
        {
            if(currentChar==tab[i][j])
            {
                suma++;
                break;
            }
            currentChar=tab[i][j];
        }
    }

    cou<<suma<<"\n";

}

void zad2()
{
    cou<<2<<"\n";

    double stat[24];
    for(int i=0; i<24; i++)
    {
        stat[i]=0;
    }

    long long wl=0;
    //24 litery

    //cout<<(int)tab[0][0]-65;
    for(int i=0; i<1876; i++)
    {
        for(int j=0; j<tab[i].size(); j++)
        {
            wl++;
            stat[(int)tab[i][j]-65]++;
        }
    }

    cou<<fixed;
    for(int i=0; i<24; i++)
    {
        cou<<setprecision(0)<<(char)(i+65)<<" "<<stat[i];
        cou<<setprecision(2)<<" ("<<stat[i]/wl*100<<"%)\n";
    }
}

void zad3()
{
    cou<<3<<"\n";

    int najw=0;
    int ilosc=0;
    string slowo;

    bool a=false;
    for(int i=0; i<1876; i++)
    {
        int cn=0;
        a=false;
        for(int j=0; j<tab[i].size(); j++)
        {
            if(tab[i][j]!='A' && tab[i][j]!='E' && tab[i][j]!='I' && tab[i][j]!='O' && tab[i][j]!='U' && tab[i][j]!='Y')
            {
                cn++;
            }
            else cn=0;

            if(cn==najw)
            {
                if(!a)ilosc++;
                a=true;
            }

            if(cn>najw)
            {
                ilosc=1;
                slowo=tab[i];
                najw=cn;
            }

        }


    }
    cou<<najw<<"\n"<<ilosc<<"\n"<<slowo;

}

int main()
{
    for(int i=0; i<1876; i++){cim>>tab[i];}
    zad1();
    zad2();
    zad3();

}
