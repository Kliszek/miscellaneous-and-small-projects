#include <iostream>



using namespace std;


#define INT_M 100002


int n;
int tab[INT_M];


int kl;
int w=0;

bool czyJestLiderem(int a)
{
    w=0;
    for(int i=0; i<n; i++)
    {
        if(tab[i]==a) w++;
    }
    if(w> n/2) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>tab[i];
    }

kl=tab[0];



for(int i=0; i<n; i++)
{
    if(tab[i]==kl) w++;
    else w--;
    if(w==0)
        kl=tab[i+1];

}
if(czyJestLiderem(kl)) cout<<kl;
else cout<<"NIE";

}
