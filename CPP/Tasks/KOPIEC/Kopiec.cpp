#include <iostream>

using namespace std;

int dlugoscKopca=0;
int kopiec[1000003];

int temp;

void dodaj(int liczba)
{
    kopiec[++dlugoscKopca]=liczba;

    int syn=dlugoscKopca;
    int ojciec=syn/2;

    while(kopiec[syn]>kopiec[ojciec])
    {
        temp=kopiec[syn];
        kopiec[syn]=kopiec[ojciec];
        kopiec[ojciec]=temp;
        syn=ojciec;
        ojciec=syn/2;
    }



}





int main()
{
    kopiec[0]=1000000;

    int a;
    while(true)
    {
        cin>>a;
        //cout<<"\n";
        dodaj(a);
        for(int i=1; i<=dlugoscKopca; i++){cout<<kopiec[i]<<" ";}
        cout<<"\n\n";

    }



}
