#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;


string hasla[200];

void wczytaj()
{
    ifstream fin;
    fin.open("hasla.txt");
    for(int i=0; i<200; i++)
    {
        fin>>hasla[i];
    }
    fin.close();
}

void zad1()
{
    int numerycznych=0;
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<hasla[i].size(); j++)
        {
            if(hasla[i][j]<48 || hasla[i][j]>57)
            {
                numerycznych--;
                break;
            }
        }
        numerycznych++;
    }
    cout<<"Hasel zlozonych z samych liter: "<<numerycznych;
}

void zad2()
{
    vector <string> powtorzenia;

    for(int i=0; i<200; i++)
    {
        for(int j=0; j<200; j++)
        {
            if(i==j) continue;
            if(hasla[i]==hasla[j])
            {
                powtorzenia.push_back(hasla[i]);
                break;
            }
        }
    }

    sort(powtorzenia.begin(), powtorzenia.end());
    reverse(powtorzenia.begin(), powtorzenia.end());

    while(!powtorzenia.empty())
    {
        cout<<powtorzenia.back()<<"\n";
        powtorzenia.pop_back();
        powtorzenia.pop_back(); //bo ka¿de haslo sie dodalo dwa razy i chrznic to
    }
}

void zad3()
{
    int wynik=0;
    for(int i=0; i<200; i++)
    {
        for(int j=0; j<hasla[i].size()-4; j++)
        {
            char tab[4]={hasla[i][j], hasla[i][j+1], hasla[i][j+2], hasla[i][j+3]};
            sort(tab, tab+4);

            if(tab[0]+1==tab[1] && tab[0]+2==tab[2] && tab[0]+3==tab[3])
            {
                wynik++;
                break;
            }
        }
    }
    cout<<"Takich hasel jest "<<wynik;
}

void zad4()
{
    int wynik=0;
    bool cyfra=false, malaLit=false, duzaLit=false;

    for(int i=0; i<200; i++)
    {
        cyfra=false; malaLit=false; duzaLit=false;

        for(int j=0; j<hasla[i].size(); j++)
        {
            if(cyfra && malaLit && duzaLit) break;
            char a=hasla[i][j];
            if(a>=48 && a<=57) cyfra=true;
            else if(a>=65 && a<=90) duzaLit=true;
            else if(a>=97 && a<=122) malaLit=true;

        }

        if(cyfra && malaLit && duzaLit) wynik++;
    }

    cout<<"Hasel spelniajacych podany warunek jest "<<wynik;
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
