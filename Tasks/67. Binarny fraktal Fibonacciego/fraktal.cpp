#include <iostream>
#include <fstream>

using namespace std;


int dlugoscF40;

string dec2bin(long long l)
{
    string w="";
    while(l>0)
    {
        w= char(l%2+'0') + w;
        l/=2;
    }
    return w;
}

void zad1()
{
    long long a=1,b=1, c=1;
    //cout<<"1\n1\n";
    for(int i=3; i<=40; i++)
    {
        c=a+b;
        a=b;
        b=c;
        if(i%10==0)
        cout<<c<<"\n";
        if(i==40) dlugoscF40=dec2bin(c).size();
    }
}

bool czyPierwsza(int l)
{
    if(l<2) return false;
    if(l==2) return true;
    for(int i=3; i*i<=l; i=i+2)
    {
        if(l%i==0) return false;
    }
    return true;
}

void zad2()
{
    long long a=1,b=1, c=1;
    for(int i=3; i<=40; i++)
    {
        c=a+b;
        a=b;
        b=c;
        if(czyPierwsza(c))
        cout<<c<<"\n";
    }
}

void zad3()
{
    ofstream fout;
    fout.open("zadanie3.txt");
    string wiersz="1";
    long long a=1,b=1, c=1;

    while(wiersz.size()<dlugoscF40) wiersz="0"+wiersz;
    fout<<wiersz<<"\n"<<wiersz<<"\n";

    for(int i=3; i<=40; i++)
    {
        c=a+b;
        a=b;
        b=c;
        wiersz=dec2bin(c);
        while(wiersz.size()<dlugoscF40) wiersz="0"+wiersz;
        fout<<wiersz<<"\n";
    }
    fout.close();
}

void zad4()
{
    string wiersz;
    long long a=1,b=1, c=1;
    int jedynek=0;

    for(int i=3; i<=40; i++)
    {
        c=a+b;
        a=b;
        b=c;
        wiersz=dec2bin(c);
        for(int j=0; j<wiersz.size(); j++)
        {
            if(wiersz[j]=='1') jedynek++;
            if(jedynek>6) break;
        }
        if(jedynek==6) cout<<wiersz<<"\n";
        jedynek=0;
        //while(wiersz.size()<dlugoscF40) wiersz="0"+wiersz;
        //cout<<wiersz<<"\n";
    }
}

int main()
{
    //cout<<czyPierwsza(21);
    cout<<"Zadanie 1\n";
    zad1();
    cout<<"\n\nZadanie 2\n";
    zad2();
    cout<<"\n\nZadanie 3\n";
    zad3();
    cout<<"w pliku zadanie3.txt";
    cout<<"\n\nZadanie 4\n";
    zad4();
    cout<<"\n";
    //cout<<dec2bin(10);
}
