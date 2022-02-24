#include <iostream>
#include <stdlib.h>

using namespace std;




int kafelki[81];
int rozw[81];

//NAPISAÆ SPRAWDZANIE DLA JEDNOWYMIAROWEJ TABELKI!!!!!!!
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


    /// ((x/27)*27) - indeks kwadratu od góry (0, 1, 2)
    /// ((x%9)/3)*3


    for(int i=0; i<27; i=i+9)
    {
        for(int j=0; j<3; j++)
        {
            if(((x/27)*27)+((x%9)/3)*3+j+i == x) continue;
            if(rozw[((x/27)*27)+((x%9)/3)*3+j+i]==rozw[x]) return false;
        }
    }



    /*for(int i=(x/3)*3; i<(y/3+1)*3; i++)
    {
        for(int j=(y/3)*3; j<(y/3+1)*3; j++)
        {
            if(i==x && j==y) continue;
            if(kafelki[i][j]==kafelki[x][y]) return false;
        }
    }*/
    return true;
    //koordy kwadratu->    x/3, y/3
    /*
2 0 2 0 0 0 0 0 0
0 0 1 0 0 0 0 0 1
3 0 0 0 0 0 0 0 0
0 0 0 0 4 0 0 0 0
0 0 0 0 0 0 0 0 5
0 0 0 0 0 0 0 0 0
3 0 0 0 0 0 0 5 0
3 0 0 0 0 0 0 0 0
0 0 1 0 0 0 5 0 0
    */
}


int main()
{
    bool kontynuowac = true;
    char znak;

    while(kontynuowac)
    {
        kontynuowac=false;

        system("cls");

        for(int i=0; i<81; i++)
        {
            cin>>kafelki[i];
            rozw[i] = kafelki[i];
        }


        cout<<"\n\n\n";



        /*for(int i=0; i<81; i++)
        {
            if(i%9==0)cout<<"\n";
            if(sprawdz(i)) cout<<"1 ";
            else cout<<"0 ";
        }*/

        int k=0;
        /*
4 0 0 1 0 0 0 0 0
7 9 0 0 8 2 0 0 3
0 0 0 4 0 3 0 0 0
6 0 1 0 0 8 0 5 0
0 8 2 0 0 0 9 1 0
0 5 0 3 0 0 8 0 6
0 0 0 8 0 6 0 0 0
1 0 0 7 3 0 0 6 2
0 0 0 0 0 4 0 0 8

    */
/*
4 2 3 1 9 7 6 8 5
7 9 6 5 8 2 1 4 3
8 1 5 4 6 3 2 7 9
6 7 1 9 2 8 3 5 4
3 8 2 6 4 5 9 1 7
9 5 4 3 7 1 8 2 6
2 3 7 8 5 6 4 9 1
1 4 8 7 3 9 5 6 2
5 6 9 2 1 4 7 3 8


4 2 0 1 9 7 6 8 5
7 9 6 5 8 2 1 4 3
8 1 5 4 6 3 2 7 9
6 7 1 9 2 8 3 5 4
3 8 2 6 4 5 9 1 7
9 0 4 3 7 1 8 2 6
2 3 7 8 5 6 4 9 1
1 4 8 7 3 9 0 6 2
5 6 9 2 1 4 7 3 8




        */

        bool blad=false;
        for(int i=0; i<81; i++)
        {
            if(!sprawdz(i))blad=true;
        }
        if(blad){cout<<"BLAD W DANYCH! NIE DA SIE ROZWIAZAC!\n\n\nJeszcze jedno sudoku?? (T/N)\n"; cin>>znak; if(znak=='T'||znak=='t')kontynuowac=true; continue; }


        while(k<81)
        {

            if(kafelki[k]!=0){k++; continue;}


            if(rozw[k]==0)rozw[k]++;
            if(sprawdz(k)) {k++; continue;}
            else if(rozw[k]==9)
            {
                //cout<<"ZERUJE";
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
