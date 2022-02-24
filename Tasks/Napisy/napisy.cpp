#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


fstream cim ("dane_napisy.txt");
ofstream cou ("wyniki_anagramy.txt");

int lit[10];
string s1, s2;

vector <string> tab;
//string sortab[1000][2];


int tt=0;

void zad1()
{
    tt=0;

    cou<<1<<"\n";
    bool jed = true;

    for(int i=0; i<1000; i++)
    {
        s1=tab[2*i];s2=tab[2*i+1];
        jed=true;
        char znak = s1[0];

        if(s1.size()!=s2.size()) continue;

        for(int j=1; j<s1.size(); j++)
        {
            if(s1[j]!=znak){jed=false; break;}
        }

        if(!jed) continue;

        for(int j=1; j<s2.size(); j++)
        {
            if(s2[j]!=znak){jed=false; break;}
        }

        if(jed) tt++;
    }
    cou<<tt<<"\n";
}

void zad2()
{
    tt=0;

    cou<<2<<"\n";
    for(int i=0; i<1000; i++)
    {


        if(tab[2*i]!=tab[2*i+1]) continue;

        tt++;
    }

    cou<<tt<<"\n";
}

void zad3()
{
    cou<<3<<"\n";
    int najw=0;

    while(tab.size()>0)
    {
        int k=0;


        string p=tab[0];
        for(int i=0; i<tab.size(); i++)
        {
            if(tab[i]==p)
            {
                tab.erase(tab.begin()+i);
                i--;
                k++;
            }
        }

        if(k>najw) najw=k;
    }

    cou<<najw;

}


int main()
{
    for(int i=0; i<2000; i++)
        {
            cim>>s1;
            sort(s1.begin(), s1.end());
            tab.push_back(s1);
        }
    zad1();
    zad2();
    zad3();

}
