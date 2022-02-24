#include <iostream>
#include <fstream>
//#include <ofstream>
#include <vector>
#include <iomanip>
#define M_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

using namespace std;



fstream cim ("punkty.txt");
ofstream cou ("dokladnosc.txt");
pair<int,int> punkty[10000];



vector <pair<int,int> > brzeg;
vector <pair<int,int> > wnetrze;


int nalezy1700[1700];

int nalezyDoKola1000=0;
int nalezyDoKola5000=0;
int nalezyDoKola=0;

void zad1()
{

    for(int i=0; i<10000; i++)
    {
        int t=(punkty[i].first-200)*(punkty[i].first-200) + (punkty[i].second-200)*(punkty[i].second-200);

        if( t == 40000 ) brzeg.push_back(punkty[i]);
        if( t <  40000 ) wnetrze.push_back(punkty[i]);

        if(i<1000 && t<=40000) nalezyDoKola1000++;
        if(i<5000 && t<=40000) nalezyDoKola5000++;
        if(t<=40000) nalezyDoKola++;

        if(i<1700 && t<=40000)
        {
            for(int j=i; j<1700; j++)
                nalezy1700[j]++;
        }
    }

    cout<<"Zad 1.\nPunkty na brzegu okregu:\n";
    for(int i=0; i<brzeg.size(); i++)
    {
        cout<<brzeg[i].first<<" "<<brzeg[i].second<<"\n";
    }
    cout<<"Liczba punktow wewnatrz okregu:\n";
    cout<<wnetrze.size();


}

void zad2()
{
    double pi_1, pi_2, pi_3;



    pi_1 = (nalezyDoKola1000*4)/(1000.0);
    pi_2 = (nalezyDoKola5000*8)/(10000.0);
    pi_3 = (nalezyDoKola   *4)/(10000.0);

    //std::cout << setprecision(4);
    cout<<setprecision(5)<<"\nZad 2.\n Pi dla 1000 punktow:\n"<<pi_1;
    cout<<setprecision(5)<<"\n Pi dla 5000 punktow:\n"<<pi_2;
    cout<<setprecision(5)<<"\n Pi dla wszystkich punktow:\n"<<pi_3;


}



void zad3()
{
    cout<<"\nZad 3.\nBlad bezwzgledny Pi dla n=1000:\n";

    for(int i=0; i<1700; i++)
    {
        double p = M_PI-( (nalezy1700[i] * 160000) / ( (i+1)*40000.0 ) );
        if(p<0) p*=(-1);
        //cout<<nalezy1700[i]<<"\n";
        if(i==999) cout<<p<<"\nBlad bezwzgledny Pi dla n=1700:\n";
        if(i==1699) cout<<p;
        cou<<setprecision(100)<<1-p<<"\n";
    }




}


int main()
{

    for(int i=0; i<1700; i++) nalezy1700[i]=0;


    for(int i=0; i<10000; i++)
    {
        cim>>punkty[i].first;
        cim>>punkty[i].second;
    }

    zad1();
    zad2();
    zad3();



}
