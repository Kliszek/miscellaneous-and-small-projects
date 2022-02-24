#include <iostream>
#include <math.h>

using namespace std;


int pieter, maks;

int kart;

int main()
{
ios_base::sync_with_stdio(false);

cin>>pieter>>maks;

kart=pow(2, pieter);

int drzewo[kart];

drzewo[0]=2000003;

int t;
for(int i=1; i<=kart; i++)
{
    cin>>drzewo[i];
    cin>>t; drzewo[i]+=t;
}




}
