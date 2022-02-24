#include <iostream>
#include <string>

//PROSZÊ NIE STAWIAÆ OCENY!! :)

using namespace std;


string tekst2;
string klucz2;
int wskaznik=0;

string zs2="";
void zad2()
{
    wskaznik=0;
//    string zs="";
    for(int i=0; i<tekst2.size(); i++)
    {
        if(tekst2[i]<65 || tekst2[i]>90) zs2+=tekst2[i];

        else
        {
            int znak=tekst2[i]-klucz2[wskaznik];
            znak+=26;
            znak=znak%26;
            znak+=65;
            //cout<<(char)znak;
            zs2+=((char)znak);

            wskaznik++;
            if(wskaznik>=klucz2.size()) wskaznik=0;
        }

    }
    cout<<zs2;
    //cout<<"\n\n\n\n"<<zs2;

}


int main()
{
    cin>>klucz2;
    cin>>tekst2;
    zad2();

    //cout<<tekst;





}
