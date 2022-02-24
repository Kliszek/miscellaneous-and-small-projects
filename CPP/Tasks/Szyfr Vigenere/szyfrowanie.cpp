#include <iostream>
#include <string>


//PROSZÊ NIE STAWIAÆ OCENY!! :)

using namespace std;

string tekst1;
string klucz;
int wskaznik=0;

void zad1()
{
    int powt=0;
    string zs="";

    for(int i=0; i<tekst1.size(); i++)
    {
        if(tekst1[i]<65 || tekst1[i]>90) zs+=tekst1[i];

        else
        {
            int znak=klucz[wskaznik]+tekst1[i]-130;
            znak=znak%26;
            znak+=65;
            //cout<<(char)znak;
            zs+=((char)znak);

            wskaznik++;
            if(wskaznik>=klucz.size()) {wskaznik=0; powt++;}
        }

    }
    cout<<zs;

}

string zs2="";

int main()
{
    cin>>klucz;
    cin>>tekst1;
    zad1();

    //cout<<tekst;





}
