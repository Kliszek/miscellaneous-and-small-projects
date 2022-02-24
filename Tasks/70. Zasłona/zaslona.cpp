#include <iostream>
#include <math.h>

using namespace std;

/*
double funkcjaF(double x)
{
    return (x*x*x*x/500.0-x*x/200.0-3.0/250.0);
}

double funkcjaG(double x)
{
    return (-x*x*x/30.0+x/20.0+1.0/6.0);
}*/

double funkcjaF(double x)
{
    return (2.0*x*x*x*x-5.0*x*x-12.0)/1000.0;
}

double funkcjaG(double x)
{
    return (-2.0*x*x*x+3.0*x+10.0)/60.0;
}

double poleTrapezu(double limPrawa, double wysokosc)
{
    return 0.5*( (funkcjaF(limPrawa)-funkcjaG(limPrawa)) + (funkcjaF(limPrawa-wysokosc)-funkcjaG(limPrawa-wysokosc)) ) * wysokosc;
}

double liczPole(int czesci)
{
    double pole=0.0;
    double dlugosc=8.0/czesci;
    for(int i=0; i<czesci; i++)
    {
        pole+=poleTrapezu(10.0-i*dlugosc, dlugosc);
    }
    return pole;
}

void zad1()
{
    int czesci=2;

    double pole1=liczPole(czesci), pole2=liczPole(czesci*2);

    while(pole1-pole2>0.001 || pole1-pole2<-0.001)
    {
        czesci*=2;
        pole1=liczPole(czesci);
        pole2=liczPole(czesci*2);
    }

    cout<<"Pozostanie materialu: "<<pole2<<" metrow kwadratowych";
}


void zad2()
{

    double obwod=8.0+8.0+(19.0+(61.0/125.0)+32.0+(2.0/3.0));

    for(double i=2.008; i<=10.00001; i+=0.008)
    {
        obwod+= sqrt( (funkcjaF(i)-funkcjaF(i-0.008))*(funkcjaF(i)-funkcjaF(i-0.008)) + (0.008*0.008) );
    }

    for(double i=2.008; i<=10.00001; i+=0.008)
    {
        obwod+= sqrt( (funkcjaG(i)-funkcjaG(i-0.008))*(funkcjaG(i)-funkcjaG(i-0.008)) + (0.008*0.008) );
    }

    //cout<<"\nObwod: "<<obwod;
    int musiKupic = obwod+1;
    if(obwod==musiKupic-1) musiKupic--;
    cout<<"\nMusi kupic: "<<musiKupic<<" metrow materialu";
}

void zad3()
{
    int lacznaDlugosc=0;
    int dlugoscPaska=0;

    int t;

    double lewaStronaPaska=9.75;
    while(lewaStronaPaska>=0)
    {
        dlugoscPaska=funkcjaF(lewaStronaPaska)-funkcjaG(lewaStronaPaska);
        //if(dlugoscPaska>funkcjaF(lewaStronaPaska)-funkcjaG(lewaStronaPaska)) cout<<"\nAAAA "<<dlugoscPaska<<" "<<funkcjaF(lewaStronaPaska)-funkcjaG(lewaStronaPaska)<<" AAAA\n";

        lacznaDlugosc+=dlugoscPaska;
        lewaStronaPaska-=0.25;
    }
    cout<<"Laczna dlugosc paskow: "<<lacznaDlugosc;
}

int main()
{

    cout.precision(3);
    cout<<fixed<<"Zadanie 1\n";
    zad1();
    cout<<"\n\nZadanie 2\n";
    zad2();
    cout<<"\n\nZadanie 3\n";
    zad3();
    cout<<"\n";


}
