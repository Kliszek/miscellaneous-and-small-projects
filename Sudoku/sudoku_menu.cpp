#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;




int kafelki[81];
int rozw[81];

bool sprawdz(int x)
{
    int liczba=rozw[x];

    if(liczba==0) return true;

    for(int i=0; i<9; i++)
    {
        if(i+(x/9)*9==x) continue;
        if(rozw[i+(x/9)*9]==rozw[x]) return false;
    }

    for(int i=0; i<9; i++)
    {
        if(x%9+i*9==x) continue;
        if(rozw[x%9+i*9]==rozw[x]) return false;
    }

    for(int i=0; i<27; i=i+9)
    {
        for(int j=0; j<3; j++)
        {
            if(((x/27)*27)+((x%9)/3)*3+j+i == x) continue;
            if(rozw[((x/27)*27)+((x%9)/3)*3+j+i]==rozw[x]) return false;
        }
    }
    return true;
}


int kursor=0;
bool koniec=false;

void wyswietlKafelki(bool pyt)
{
    system("cls");
    if(kursor==0) cout<<"-------------------------\n| * ";
    else cout<<"-------------------------\n| "<<kafelki[0]<<" ";
    for(int i=1; i<81; i++)
    {
        if(i%27==0)cout<<"|\n-------------------------\n| ";
        else if(i%9==0)cout<<"|\n| ";
        else if(i%3==0&&i!=0)cout<<"| ";
        if(kursor==i && !koniec) cout<<"* ";
        else cout<<kafelki[i]<<" ";
    }   cout<<"|\n-------------------------\n\n";
    if(pyt)
    {
        if(koniec) cout<<"[*Zaakceptuj ]   (spacja)";
        else cout<<"[ Zaakceptuj ]";
    }
}


int main()
{
    bool kontynuowac = true;
    char znak;

    while(kontynuowac)
    {
        for(int i=0; i<81; i++)
        {
            kafelki[i]=0;
        }

        kursor=0;
        koniec=false;
        kontynuowac=false;
        bool wpisywanie=true;

        int c=0;
        while(wpisywanie)
        {
            wyswietlKafelki(true);

            switch((c=getch()))
            {
                case 27:
                    return 0;
                    break;
                case 32:
                    if(koniec)
                    wpisywanie=false;
                    break;
                case 72:
                    if(koniec) koniec=false;
                    else if(kursor>8) kursor-=9;
                    break;
                case 80:
                    if(kursor<72) kursor+=9;
                    else koniec=true;
                    break;
                case 75:
                    if(kursor%9!=0 && !koniec) kursor--;
                    break;
                case 77:
                    if((kursor+1)%9!=0 && !koniec) kursor++;
                    break;
                default:
                    if(c>=48 && c<58)
                    {
                        kafelki[kursor]=c-48;
                    }
                    if(kursor!=80 && c!=224)kursor++;
                    else if(kursor==80 && c!=224)koniec=true;
                    break;
            }

        }

        system("cls:");
        wyswietlKafelki(false);

        //WCZYTYWANIE DANYCH========================================================================================
        //USTAWIANIE WSZYSTKICH KAFELKÓW NA 0
        for(int i=0; i<81; i++)
        {
            rozw[i]=kafelki[i];
        }
        //==========================================================================================================

        cout<<"\n\n";



        //SPRAWDZANIE CZY NIE MA BLEDU  ===================================================================================
        bool blad=false;
        for(int i=0; i<81; i++)
        {
            if(!sprawdz(i))blad=true;
        }
        if(blad){cout<<"BLAD W DANYCH! NIE DA SIE ROZWIAZAC!\n\n\nJeszcze jedno sudoku?? (T/N)\n"; cin>>znak; if(znak=='T'||znak=='t')kontynuowac=true; continue; }
        //=================================================================================================================


        int k=0;


        while(k<81)
        {
            //Jeœli kafelek by³ ju¿ zdefiniowany, pomiñ go
            if(kafelki[k]!=0){k++; continue;}


            if(rozw[k]==0)rozw[k]++;
            if(sprawdz(k)) {k++; continue;}
            else if(rozw[k]==9)
            {
                rozw[k]=0;
                k--;
                while(true)
                {
                    if(kafelki[k]!=0) k--;
                    else if(rozw[k]==9)
                    {
                        rozw[k]=0;
                        k--;
                    }
                    else break;
                }
                rozw[k]++;
            }
            else {rozw[k]++; continue;}
        }



        cout<<"-------------------------\n| "<<rozw[0]<<" ";
        for(int i=1; i<81; i++)
        {
            if(i%27==0)cout<<"|\n-------------------------\n| ";
            else if(i%9==0)cout<<"|\n| ";
            else if(i%3==0&&i!=0)cout<<"| ";
            cout<<rozw[i]<<" ";
        }   cout<<"|\n-------------------------\n\n";





        cout<<"\nJeszcze jedno sudoku?? (T/N)\n";
        cin>>znak;
        if(znak=='T'||znak=='t') kontynuowac=true;
    }

}

