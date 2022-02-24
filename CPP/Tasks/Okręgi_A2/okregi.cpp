#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

fstream cim ("dane.txt");


int okregiX[100];
int okregiY[100];
int promienie[100];


void zad1()
{
    stack <int> lista;
    int najm=1000;
    for(int i=0; i<100; i++)
    {
        if(promienie[i]==najm) lista.push(i);

        if(promienie[i]<najm)
            {
                while(lista.size()>0) lista.pop();
                lista.push(i);
                najm=promienie[i];
            }
    }

    cout<<"4.1)\n\n";
    for(int i=0; i<lista.size(); i++)
    {
        cout<<okregiX[lista.top()]<<" "<<okregiY[lista.top()]<<" "<<promienie[lista.top()]<<"\n";
        lista.pop();
    }
    cout<<"\n";

}


void zad2()
{

    int li[100];
    for(int i=0; i<100; i++) li[i]=0;

    for(int i=0; i<100; i++)
    {

        for(int j=0; j<100; j++)
        {
            if(j==i) continue;

            int odl_2=(okregiX[i]-okregiX[j])*(okregiX[i]-okregiX[j])+(okregiY[i]-okregiY[j])*(okregiY[i]-okregiY[j]);

            if(odl_2<promienie[i]*promienie[i]) li[i]++;

        }

    }
    int naajw=0;
    int w;
    for(int i=0; i<100; i++)
    {
        if(li[i]>naajw)
        {
            w=i;
            naajw=li[i];
        }
    }

    cout<<"4.2)\n\n";
    cout<<okregiX[w]<<" "<<okregiY[w]<<" "<<promienie[w]<<"\n"<<li[w]<<"\n\n";
}


void zad3()
{
    int par=0;

    cout<<"4.3)\n\n";
    for(int i=0; i<100; i++)
    {

        for(int j=0; j<100; j++)
        {
            if(j==i) continue;

            int odl_2=(okregiX[i]-okregiX[j])*(okregiX[i]-okregiX[j])+(okregiY[i]-okregiY[j])*(okregiY[i]-okregiY[j]);

            if(odl_2==(promienie[j]+promienie[i])*(promienie[j]+promienie[i]) ||  odl_2==(promienie[j]-promienie[i])*(promienie[j]-promienie[i]) )
            {
                par++;
                cout<<okregiX[i]<<" "<<okregiY[i]<<" "<<promienie[i]<<" "<<okregiX[j]<<" "<<okregiY[j]<<" "<<promienie[j]<<"\n";
            }

        }

    }

}


int main()
{
    for(int i=0; i<100; i++)
    {
        cim>>okregiX[i];
        cim>>okregiY[i];
        cim>>promienie[i];
    }

    zad1();
    zad2();
    zad3();
}
