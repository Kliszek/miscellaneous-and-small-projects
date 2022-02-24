#include <iostream>
//#include <algorithm>

using namespace std;



int KWOTA;
int nominalow;

int a=nominalow-1;

int najm;
int j;

int main()
{
cin>>KWOTA>>nominalow;

int nominaly[nominalow];

for(int i=0; i<nominalow; i++)
{
    cin>>nominaly[i];
}
//sort(nominaly, nominaly+nominalow);

int wydawanie[KWOTA+1];

wydawanie[0]= -1;
for(int i=1; i<=KWOTA; i++)
{
    if(i==nominaly[a]){a--; wydawanie[i]=1; continue;}

    najm=100013;

    j=1;
    while(i-j >= j)
        {
            if(wydawanie[i-j]== -1 || wydawanie[j]== -1) {j++; continue;}
            if(wydawanie[i-j]+wydawanie[j]<najm) {najm=wydawanie[i-j]+wydawanie[j];}
            j++;
        }
    wydawanie[i]=najm;


}
if(najm==100013) cout<<"NIE";
else cout<<wydawanie[KWOTA];
}
