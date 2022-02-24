#include <iostream>
#include <fstream>

using namespace std;

fstream cim ("systemy.txt");


int liczbyD[1000];
string liczbyB[1000];

int binToDec(string l)
{
    int w=0;
    int pot=1;
    for(int i=l.size()-1; i>=0; i--)
    {
        if(l[i]=='1')
            w+=pot;
        pot*=2;
    }
    return w;
}


void zad1()
{
    cout<<"\n\na)\n";
    int najw=0, najm=1000000001;

    for(int i=0; i<1000; i++)
    {

        if(liczbyD[i]<najm) najm=liczbyD[i];
        if(liczbyD[i]>najw) najw=liczbyD[i];

    }

    cout<<"Najw: "<<najw<<", Najm: "<<najm<<"\n";
}


void zad2()
{
    cout<<"\n\nb)\n";
    int najw=0, najm=1000000001;
    int t1;
    for(int i=0; i<1000; i++)
    {
        t1=binToDec(liczbyB[i]);

        if(t1<najm) najm=t1;
        if(t1>najw) najw=t1;

    }

    cout<<"Najw: "<<najw<<", Najm: "<<najm<<"\n";
}

void zad3()
{
    cout<<"\n\nc)\n";
    for(int i=0; i<1000; i++)
    {
        if(liczbyD[i]==binToDec(liczbyB[i]))
            cout<<liczbyD[i]<<" "<<liczbyB[i]<<"\n";
    }



}

int main()
{
    for(int i=0; i<1000; i++)
    {
        cim>>liczbyD[i];
        cim>>liczbyB[i];
    }

    zad1();
    zad2();
    zad3();
}
