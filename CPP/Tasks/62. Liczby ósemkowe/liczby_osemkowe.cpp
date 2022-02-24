#include <iostream>
#include <fstream>

using namespace std;

string osemkowo[1000];
int dziesietnie[1000];

int oct2dec(string l)
{
    int w=0;
    for(int i=0; i<l.size(); i++)
    {
        w*=8;
        w+=l[i]-'0';
    }
    return w;
}

string dec2oct(int l)
{
    string w="";
    while(l>0)
    {
        w=(char)(l%8+48)+w;
        l/=8;
    }
    return w;
}

void wczytaj()
{
    ifstream fin1, fin2;
    fin1.open("liczby1.txt");
    fin2.open("liczby2.txt");
    for(int i=0; i<1000; i++)
    {
        fin1>>osemkowo[i];
        fin2>>dziesietnie[i];
    }
}

void zadanie_a()
{
    int najmn=oct2dec(osemkowo[0]);
    int najw=najmn;

    for(int i=0; i<1000; i++)
    {
        if(oct2dec(osemkowo[i])>najw) najw=oct2dec(osemkowo[i]);
        if(oct2dec(osemkowo[i])<najmn) najmn=oct2dec(osemkowo[i]);
    }
    cout<<"Najwieksza: "<<dec2oct(najw);
    cout<<"\nNajmniejsza: "<<dec2oct(najmn)<<"\n";
}

void zadanie_b()
{
    int najd=0, dlug=1, najdInd=0, ind=0;
    for(int i=0; i<1000; i++)
    {
        if(dziesietnie[i]<=dziesietnie[i+1])
        {
            dlug++;
            if(dlug>najd) {najd=dlug; najdInd=ind;}
        }
        else
        {
            dlug=1;
            ind=i+1;
        }
    }
    cout<<"Najdluzszy niemalejacy ciag zaczyna sie "<<dziesietnie[najdInd]<<" i ma dlugosc "<<najd<<"\n";
}

void zadanie_c()
{
    int rowne=0;
    int wieksza=0;
    for(int i=0; i<1000; i++)
    {
        if(oct2dec(osemkowo[i])==dziesietnie[i]) rowne++;
        else if(oct2dec(osemkowo[i])>dziesietnie[i]) wieksza++;
    }
    cout<<"Takie same: "<<rowne;
    cout<<"\nOsemkowa wieksza: "<<wieksza<<"\n";
}

void zadanie_d()
{
    int normalnie=0;
    int wOsemkowym=0;
    for(int i=0; i<1000; i++)
    {
        int a=dziesietnie[i];
        while(a>0)
        {
            if(a%10==6) normalnie++;
            a/=10;
        }
        string t=dec2oct(dziesietnie[i]);
        for(int j=0; j<t.size(); j++)
        {
            if(t[j]=='6') wOsemkowym++;
        }
    }

    cout<<"Cyfra 6 wystepuje "<<normalnie<<" razy\nW systemie osemkowym wystepowalaby "<<wOsemkowym<<" razy";
}

int main()
{
    wczytaj();
    zadanie_a();
    cout<<"\n";
    zadanie_b();
    cout<<"\n";
    zadanie_c();
    cout<<"\n";
    zadanie_d();
    cout<<"\n";
}
