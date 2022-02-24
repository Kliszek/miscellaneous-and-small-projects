#include <iostream>

using namespace std;

const int N = 2*10*1000+3;

int tarasow, kasy, kasyN;

int tarasy[N];
int tarasyN[N]; //tarasy od konca


int main()
{
    ios_base::sync_with_stdio(false);
cin>>tarasow>>kasy;
kasyN=kasy;


for(int i=0; i<tarasow; i++) {cin>>tarasy[i]; tarasyN[tarasow-1-i]=tarasy[i];}


int najwiekszaDlugosc=0;
int j=0;    //taras, od ktorego zaczal turysta
//cout<<"\nIDZIE W LEWO\n";


j=0;
for(int i=0;i<tarasow-1;i++)
{


    if(tarasy[i+1]-tarasy[i]>0) //nastepny taras jest wyzej
    {
        if(tarasy[i+1]-tarasy[i]>kasy)  //nie mamy wystarczaj¹co kredytów
        {


        }



    }

    else
    {




    }



}





for(int i=0;;i++)
{
    if(i==tarasow) break;
//    cout<<"kasy: "<<kasy<<"\n";
//    cout<<"Jest na tarasie "<< i<<"\nWysokosc tego tarasu: "<<tarasy[i]<<"\nWysokosc nastepnego tarasu: "<<tarasy[i+1]<<"\n";
    if(tarasy[i+1]-tarasy[i]>kasy)
        {

            if(tarasy[j+1]>tarasy[j]) kasy+=tarasy[j+1]-tarasy[j];
            j++;
            //i--;
        }
    if(i-j+1>najwiekszaDlugosc) najwiekszaDlugosc=i-j+1;
    if(tarasy[i+1]>tarasy[i]) kasy-=tarasy[i+1]-tarasy[i];




}

j=0;

for(int i=0;;i++)
{
    if(i==tarasow) break;
//    cout<<"kasy: "<<kasy<<"\n";
//    cout<<"Jest na tarasie "<< i<<"\nWysokosc tego tarasu: "<<tarasy[i]<<"\nWysokosc nastepnego tarasu: "<<tarasy[i+1]<<"\n";
    if(tarasyN[i+1]-tarasyN[i]>kasyN)
        {

            if(tarasyN[j+1]>tarasyN[j]) kasyN+=tarasyN[j+1]-tarasyN[j];
            j++;
            //i--;
        }
    if(i-j+1>najwiekszaDlugosc) najwiekszaDlugosc=i-j+1;
    if(tarasyN[i+1]>tarasyN[i]) kasyN-=tarasyN[i+1]-tarasyN[i];




}
/*
j=tarasow-1;
for(int i=tarasow-1;;i--)
{
    if(i==-1) break;
    if(tarasy[i-1]-tarasy[i]>kasy)
        {

            if(tarasy[j-1]>tarasy[j]) kasy+=tarasy[j-1]-tarasy[j];
            j--;

        }
    if(j-i+1>najwiekszaDlugosc) najwiekszaDlugosc=j-i+1;
    if(tarasy[i-1]>tarasy[i]) kasy-=tarasy[i-1]-tarasy[i];




}
*/
cout<<najwiekszaDlugosc;

}
