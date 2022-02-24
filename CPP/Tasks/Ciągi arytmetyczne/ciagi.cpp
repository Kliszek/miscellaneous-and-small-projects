#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

fstream cim ("ciagi.txt");

vector <int> ciagi[100];
//int dlugCiag[100];


void zad1()
{
    cout<<"Zad 1.\n";
    int arytm=0;
    int najwRoz=0;
    //int tempRoz=0;

    for(int i=0; i<100; i++)
    {
        if(ciagi[i].size()<5) continue;
        int roznica = ciagi[i][1]-ciagi[i][0];
        for(int j=2; j<ciagi[i].size(); j++)
        {
            if(ciagi[i][j]-ciagi[i][j-1]!=roznica)
            {
                arytm--;
                roznica=0;
                break;
            }
        }
        arytm++;
        if(roznica>najwRoz) najwRoz=roznica;
    }
    cout<<"Ciagow arytmetycznych: "<<arytm<<"\nNajwieksza roznica: "<<najwRoz<<"\n";
}

void sz()
{
    cout<<"a==";
    for(int i=1; i<=100; i++) cout<<i*i*i<<"||a==";
}

int main()
{
    int t1,t2;
    for(int i=0; i<100; i++)
    {
        cim>>t1;
        for(int j=0; j<t1; j++)
        {
            cim>>t2;
            ciagi[i].push_back(t2);
        }
    }

    sz();
}
