#include <iostream>
#include <fstream>

using namespace std;

fstream cim ("liczby.txt");

int liczby[1000];



void zad1()
{
    cout<<"Zad 1.\n";

    int w=0;
    for(int i=0; i<1000; i++)
    {
        //cout<<"i="<<i<<"\n";
        int a=liczby[i];
        //cout<<"a="<<a<<"\n";
        if(a%2==0) continue;
        int czynnikow=0;
        for(int j=3; j<=a;j=j+2)
        {
            if(czynnikow>3) break;
            if(a%j==0)
            {
                czynnikow++;
                while(a%j==0) a/=j;
            }
        }
        if(czynnikow==3) w++;
    }
    cout<<w;
}

int odwroc(int l)
{
    int t=0;
    while(l>0)
    {
        t*=10;
        t+=l%10;
        l/=10;
    }
    return t;
}

void zad2()
{
    int palindromow=0;
    cout<<"\nZad 2.\n";
    for(int i=0; i<1000; i++)
    {
        //cout<<"\nliczba: "<<liczby[i];
        int k=0;
        int t=liczby[i];

        if(t+odwroc(t)==odwroc(t+odwroc(t))) palindromow++;
        /*k=odwroc(t);
        t=liczby[i]+k; //suma liczby i jej odwrotności

        string pal="";
        while(t>0)
        {
            pal = (char)(t%10 + 48) + pal;
            t/=10;
        }
        cout<<"\nsuma jej i jej odwrotnosci: "<<pal<<"\n";
        //zamiana na stringa bo latwiej
        bool czypalindrom=true;

        for(int j=0;j<pal.size(); j++)
        {
            if(pal[j]!=pal[pal.size()-j-1]) {czypalindrom=false; break;}
        }
        if(czypalindrom) palindromow++;
        //cout<<"\nszuk: "<<k+liczby[i]<<"\n";
        */
    }
    cout<<palindromow<<"\n";
}

void zad3()
{
    cout<<"Zad 3.\n";
    int moc[8]; for(int i=0; i<8; i++) moc[i]=0;
    int najmnJ=liczby[0], najwJ=liczby[0];

    for(int i=0; i<1000; i++)
    {
        int mocT=0;
        int n=liczby[i];
        while(n>=10)
        {
            int a=n;
            n=1;
            while(a>0)
            {
                n*=a%10;
                a/=10;
            }
            mocT++;
        }
        if(mocT<=8) moc[mocT-1]++;
        if(mocT==1 && liczby[i]>najwJ) najwJ=liczby[i];
        else if(mocT==1 && liczby[i]<najmnJ) najmnJ=liczby[i];
    }


    for(int i=0; i<8; i++)
    {
        cout<<"Moc "<<i+1<<": "<<moc[i]<<"\n";
    }
    cout<<"Najmniejsza z moca 1: "<<najmnJ;
    cout<<"\nNajwieksza z moca 1: "<<najwJ;
}


int main()
{
    for(int i=0; i<1000; i++)
    {
        cim>>liczby[i];
    }
    zad1();
    //cout<<"TEST "<<odwroc(1023)<<"\n\n";
    zad2();
    zad3();
    //Wszystkie prawie odpowiedzi Ÿle

}
