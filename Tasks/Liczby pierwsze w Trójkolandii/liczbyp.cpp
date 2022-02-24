#include <iostream>


using namespace std;





bool czyDajeReszteJeden(int l)
{
    if(l%3==1) return true;
    return false;
}

bool czyJestPierwsza(int l)
{
    if(!czyDajeReszteJeden(l)) return false;

    bool czyTak=true;

    for(int i=l/2+1; i>1; i--)
    {
        if(l%i!=0) continue; //czy jest dzielnikiem
        //cout<<i<<" jest dzielnikiem "<<l<<"\n";

        if(czyDajeReszteJeden(i)) {czyTak=false; break;}

        //cout<<"i nie daje reszty 3\n";
    }

    //if(czyTak) cout<<"\nliczba "<<l<<" jest pierwsza\n\n\n";
    //else cout<<"\nliczba "<<l<<"nie jest pierwsza\n\n\n";

    return czyTak;
}

int main()
{
    cout<<"Zakres 1-20:\n";
    int a1=0;
    for(int i=1; i<=20; i=i+3)
    {
        if(czyJestPierwsza(i)) a1++;
    }
    cout<<a1<<"\n\n";

    cout<<"Zakres 21-1000:\n";
    int a2=0;
    for(int i=22; i<=1000; i=i+3)
    {
        if(czyJestPierwsza(i)) a2++;
    }
    cout<<a2<<"\n\n";

    cout<<"Zakres 1001-1000000:\n";
    int a3=0;
    for(int i=1003; i<=1000000; i=i+3)
    {
        if(czyJestPierwsza(i)) a3++;
    }
    cout<<a3<<"\n\n";

    cout<<"Zakres 1000001-10000000:\n";
    int a4=0;
    for(int i=1000003; i<=10000000; i=i+3)
    {
        if(czyJestPierwsza(i)) a4++;
    }
    cout<<a4<<"\n\n";



}
