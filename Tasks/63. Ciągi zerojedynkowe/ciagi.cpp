#include <iostream>
#include <fstream>

using namespace std;

string ciagi[1000];

void wczytaj()
{
    ifstream fin;
    fin.open("ciagi.txt");
    for(int i=0; i<1000; i++)
    {
        fin>>ciagi[i];
    }
}


void zadanie_a()
{
    //int dwucykl=0;
    for(int i=0; i<1000; i++)
    {
        if(ciagi[i].size()%2!=0) continue;

        bool czyDwucykl=true;
        for(int j=0; j<ciagi[i].size()/2; j++)
        {
            if(ciagi[i][j]!=ciagi[i][ciagi[i].size()/2+j])
            {
                czyDwucykl=false;
                break;
            }
        }
        if(czyDwucykl) cout<<ciagi[i]<<"\n";
            //0 1 2 3 4 5
    }

    //cout<<"\n\nDwucyklicznych ciagow: "<<dwucykl;
}

void zadanie_b()
{
    int bezSasJed=0; //bez sasiadujacych jedynek
    for(int i=0; i<1000; i++)
    {
        bool czyOk=true;
        for(int j=0; j<ciagi[i].size()-1; j++)
        {
            if(ciagi[i][j]=='1' && ciagi[i][j+1]=='1')
            {
                czyOk=false;
                break;
            }
        }

        if(czyOk) bezSasJed++;
    }
    cout<<"Ciagi bez sasiadujacych jedynek: "<<bezSasJed;
}

int bin2dec(string l)
{
    int w=0;
    for(int i=0; i<l.size(); i++)
    {
        w*=2;
        w+=l[i]-'0';
    }
    return w;
}

bool czyPierwsza(int l)
{
    if(l<2) return false;
    if(l==2) return true;
    if(l%2==0) return false;
    for(int i=3; i*i<=l; i=i+2)
    {
        if(l%i==0) return false;
    }
    return true;
}

void zadanie_c()
{
    int polpierwszych=0;
    int najmn=bin2dec(ciagi[0]);
    int najw=najmn;
    for(int i=0; i<1000; i++)
    {
        bool czyPolPierwsza=false;
        int liczba=bin2dec(ciagi[i]);
        for(int j=2; j<liczba/2+1; j++)
        {
            if(liczba%j==0)
            {
                if(czyPierwsza(j) && czyPierwsza(liczba/j))
                    czyPolPierwsza=true;
                break;
            }
        }
        if(czyPolPierwsza)
        {
            polpierwszych++;
            if(liczba>najw) najw=liczba;
            if(liczba<najmn) najmn=liczba;
        }
    }
    cout<<"Liczb polpierwszych: "<<polpierwszych<<"\nNajmniejsza z nich: "<<najmn<<"\nNajwieksza z nich: "<<najw;
}

int main()
{
    wczytaj();
    //cout<<bin2dec("1111");
    cout<<"Zadanie a:\n";
    zadanie_a();
    cout<<"\n\nZadanie b:\n";
    zadanie_b();
    cout<<"\n\nZadanie c:\n";
    zadanie_c();
    cout<<"\n";
    //cout<<czyPierwsza(2);

}
