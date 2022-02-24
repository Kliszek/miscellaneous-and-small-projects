#include <iostream>


using namespace std;

//bool ktoreStaty[5] = {0,0,0,0,1};

bool liczPalindromy = false;

int stats[5] = {-1,0,0,0,0};        //do stringa dodaje jedna spacje na koncu, stad poczatkowa ilosc spacji to -1


string tresc;


void palindrom(int p, int k)
{
    //cout<<"\nPoczatek slowa: "<<p<<"\nKoniec slowa: "<<k<<"\n";
    //int dlugosc = k-p+1;
    if(p==k)
    {
        stats[4]++;
        //cout<<"\nJest to palindron jednoliterowy\n";
        return;
    }

    for(int i=k; i>=p; i--)
    {
        int aktualna = k-i+p;

        if((int)tresc[i] == (int)tresc[aktualna])
        {
            //cout<<" Znaki sa takie same\n";
            continue;
        }

        if((int)tresc[i]-32 == (int)tresc[aktualna])
        {
            //cout<<" Znak od konca jest wieksza litera\n";
            continue;
        }
        if((int)tresc[i]+32 == (int)tresc[aktualna])
        {
            //cout<<" Znak od konca jest mniejsza litera\n";
            continue;
        }

        //cout<<"\nNie jest to palindron\n";
        return;
    }
    //cout<<"\nJest to palindron\n";
    stats[4]++;
}




int main()
{
    //ios_base::sync_with_stdio(false);

    int ilosc;
    cin>>ilosc;
    int ktoreStaty[ilosc];
    for(int i=0;i<ilosc;i++){cin>>ktoreStaty[i]; if(ktoreStaty[i]==5) liczPalindromy=true;}


    getline(cin, tresc);
    getline(cin, tresc);

    tresc += ' ';
    int dlugosc = tresc.size();


    bool rozpoczetaCyfra = false;
    bool rozpoczeteSlowo = false;
    bool slowoPrzedKropka = false;
    int poczatekSlowa;

    for(int i=0; i<dlugosc; i++)
    {
        int ascii = (int)tresc[i];


        if( ascii >= 65 && ascii <=90) ascii+=32;   //zamiana wszystkich wielkich liter na ma³e

        if( ascii>=48 && ascii<=57 )  //cyfry
        {
            if(!rozpoczetaCyfra) stats[1]++;
            rozpoczetaCyfra=true;
            if(rozpoczeteSlowo){rozpoczeteSlowo=false; if(liczPalindromy)palindrom(poczatekSlowa, i-1);}
        }



        else if( ascii>=97 && ascii<=122 )  //litery
        {
            if(!rozpoczeteSlowo) {poczatekSlowa=i; stats[2]++;}
            rozpoczeteSlowo = true;
            slowoPrzedKropka = true;
            rozpoczetaCyfra = false;
            //if(rozpoczetaCyfra){rozpoczetaCyfra=false; stats[1]++;}

        }

        else if( ascii==46 )        //kropka
        {
            if(slowoPrzedKropka) stats[3]++;
            if(rozpoczeteSlowo){if(liczPalindromy)palindrom(poczatekSlowa, i-1);}
            rozpoczeteSlowo=false;
            rozpoczetaCyfra=false;
            slowoPrzedKropka=false;


        }


        else        //spacja lub tabulator  (lub ? , !)
        {
            if(ascii==32) stats[0]++;         //jeœli nie s¹ to ! ? ,
            if(rozpoczetaCyfra){rozpoczetaCyfra=false;}
            if(rozpoczeteSlowo){rozpoczeteSlowo=false; if(liczPalindromy)palindrom(poczatekSlowa, i-1);}
        }

    }
//cout<<"\n";
//for(int i=0; i<5; i++) cout<<stats[i]<<" ";
//cout<<"\n";

    for(int i=0; i<ilosc; i++)
    {
        cout<<stats[ktoreStaty[i]-1]<<" ";




    }

}
