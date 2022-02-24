#include <iostream>

using namespace std;


string wyraz;
int maks=0;
int a=0;

int main()
{
    getline(cin, wyraz);

    for(int i=0; i<wyraz.size(); i++)
    {
        if((int)wyraz[i]==97) a++;
        else a=0;
        if(a>maks) maks=a;
    }

    if(maks==0){cout<<"BRAK"; return 0;}
    for(int i=0; i<maks; i++)
    {
        cout<<"a";
    }


}
