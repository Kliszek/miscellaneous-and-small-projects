#include <iostream>


using namespace std;


int bok;

int kierunek=0,   //0-N, 1-E, 2-S albo 3-W
    skret=1;      //1-R albo 3-L


int krok=1;

string strKier, strSkr;


int tx1, tx2, ty1, ty2;

pair <int, int> poz=make_pair(1,1);

int dx[4]={0, 1, 0, -1};
int dy[4]={1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>bok;

    cin>>strKier>>strSkr;

    if(strSkr=="LEWO") skret=3;

         if(strKier=="POLNOC"){kierunek=0; if(skret==1) poz=make_pair(1,1); else poz=make_pair(bok,1);}
    else if(strKier=="WSCHOD"){kierunek=1; if(skret==1) poz=make_pair(1,bok); else poz=make_pair(1,1);}
    else if(strKier=="POLUDNIE"){kierunek=2; if(skret==1) poz=make_pair(bok,bok); else poz=make_pair(1,bok);}
    else if(strKier=="ZACHOD"){kierunek=3; if(skret==1) poz=make_pair(bok,1); else poz=make_pair(bok,bok);}


    cin>>tx1>>tx2>>ty1>>ty2;

    int T[tx2-tx1+1][ty2-ty1+1];

    int poprzedniSkret=0;
    int ws=2*bok; //wspolczynnik


    //cout<<"\ntx1="<<tx1<<" tx2="<<tx2<<" ty1="<<ty1<<" ty2="<<ty2<<"\n";
    for(int i=1; i<=bok*bok; i++)
    {
        //cout<<"Krok: "<<i<<" , kierunek "<<kierunek<<", skret"<<skret<<"\n";
        //cout<<"Poz: ("<<poz.first<<", "<<poz.second<<")\n";

        if(tx1<=poz.first && poz.first<=tx2 && ty1<=poz.second && poz.second<=ty2)  //-jest w polu
        {
            //cout<<"      >> Dodaje liczbe "<<i<<"\n";
            T[poz.first-tx1][poz.second-ty1]=i; //UWAGA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        }

        if(i==poprzedniSkret+ws/2)   //czy jest w rogu
        {
            poprzedniSkret=i;
            ws--;
            kierunek=(kierunek+skret)%4;
            //cout<<">Skret w "<<skret<<"\n";
        }

        poz.first+=dx[kierunek];
        poz.second+=dy[kierunek];


    }

    for(int i=ty2-ty1; i>=0; i--)
    {
        for(int j=0; j<=tx2-tx1; j++)
        {
            cout<<T[j][i]<<" ";
        }
        cout<<"\n";

    }





}
