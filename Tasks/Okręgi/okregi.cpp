#include <iostream>
#include <fstream>



using namespace std;





fstream cim ("okregi.txt");
ofstream cou ("wyniki_okregi.txt");

double okregi[2000][3];


double wart(double tt)
{
    if(tt<0) return -tt;
    return tt;
}


void zad1()
{
    int k=0,l=0,m=0,n=0,o=0;

    cou<<"1.\n";
    for(int i=0; i<2000; i++)
    {
#define a okregi[i][0]
#define b okregi[i][1]
#define c okregi[i][2]
        if(c>wart(a) || c>wart(b)) {o++; continue;}
        if(a>0 && b>0 && c<a && c<b) {k++; continue;}
        if(a<0 && b>0 && c<(-a) && c<b) {l++; continue;}
        if(a<0 && b<0 && c<(-a) && c<(-b)) {m++; continue;}
        if(a>0 && b<0 && c<a && c<(-b)) {n++; continue;}
#undef a
#undef b
#undef c

    }

    cou<<k<<"\n"<<l<<"\n"<<m<<"\n"<<n<<"\n"<<o<<"\n";

}


void zad2()
{

    cou<<"2.\n";
    int pary=0;
    for(int i=0; i<2000; i++)
    {
        for(int j=i; j<2000; j++)
        {
            if(okregi[i][0]==-okregi[j][0] && okregi[i][1]==okregi[j][1] && okregi[i][2]==okregi[i][2]) pary++;
            if(okregi[i][0]==okregi[j][0] && okregi[i][1]==-okregi[j][1] && okregi[i][2]==okregi[i][2]) pary++;

        }
    }
    cou<<pary<<"\n";
}


void zad3()
{

    cou<<"3.\n";
    int prost=0;
    for(int i=0; i<2000; i++)
    {
        for(int j=i; j<2000; j++)
        {
            if(okregi[i][0]==-okregi[j][1] && okregi[i][1]==okregi[j][0] && okregi[i][2]==okregi[i][2]) prost++;
            if(okregi[i][0]==okregi[j][1] && okregi[i][1]==-okregi[j][0] && okregi[i][2]==okregi[i][2]) prost++;

        }
    }
    cou<<prost<<"\n";
}

int main()
{
    for(int i=0; i<2000; i++)
    {
        for(int j=0; j<3; j++)
        {
            cim>>okregi[i][j];
        }
    }

    zad1();
    zad2();
    zad3();
}
