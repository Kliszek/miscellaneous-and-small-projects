#include <iostream>


using namespace std;

double liczba=0.0000000;
//float x=0.0000;

double zmiana=1.0000000;


float liczby[6];

double wynik;

bool aaa=0;

bool wielomian()
{
    wynik=  liczba*liczba*liczba*liczba*liczba*liczby[0]+
            liczba*liczba*liczba*liczba*liczby[1]+
            liczba*liczba*liczba*liczby[2]+
            liczba*liczba*liczby[3]+
            liczba*liczby[4]+
            liczby[5];


    if(wynik<0.0001 && wynik> -0.0001) {cout<<liczba; return 1;} //wynik==0

    if(wynik> -0.0001)  //wynik>0
    {
        if(aaa!=0) { zmiana*=0.9; aaa=0;}
        liczba-=zmiana;
    }

    if(wynik< 0.0001)  //wynik>0
    {
        if(aaa!=1) { zmiana*=0.9; aaa=1;}
        liczba+=zmiana;
    }
    //if(wynik<0) wynik*= -1;

    return 0;
}

int main()
{
    cin>>liczby[0]>>liczby[1]>>liczby[2]>>liczby[3]>>liczby[4]>>liczby[5];


    while(true)
    {
        if(wielomian()==1) break;
    }

    return 0;

}
