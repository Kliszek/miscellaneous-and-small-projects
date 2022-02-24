#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


//zminne do kopca
int kopiec[1000003];

int dlugoscKopca=0;


priority_queue <int> test;

//zminne do trikontenerowca
int M,N;
pair<int,int> t;
int wartosc=0;
//bool prowadnice[500005];
//pair<int,int> plyta;
pair <int , int> plyty[1000003];


void dodaj(int liczba)
{

    kopiec[++dlugoscKopca]=liczba;
    int syn = dlugoscKopca;
    int ojciec= syn/2;

    while(kopiec[syn]>kopiec[ojciec])
    {
        swap(kopiec[syn], kopiec[ojciec]);

        syn=ojciec;
        ojciec= syn/2;
    }
}



int usun()
{
    int najw=kopiec[1];
    swap(kopiec[1], kopiec[dlugoscKopca]);
    dlugoscKopca--;

    int ojciec=1;
    int syn=(dlugoscKopca>2 && kopiec[2] < kopiec[3]) ? 3 : 2;
    //if(dlugoscKopca<=2) syn=kopiec[2];
    if(dlugoscKopca==1) {return kopiec[2];}
    while(kopiec[ojciec]<kopiec[syn])
    {


        swap(kopiec[ojciec], kopiec[syn]);


        ojciec=syn;

        if(ojciec*2+1 > dlugoscKopca)
        {
            if(ojciec*2 > dlugoscKopca) return najw;

            else syn=ojciec*2;
        }


         else syn=kopiec[ojciec*2] > kopiec[ojciec*2+1] ? ojciec*2 : ojciec*2+1;

    }

    return najw;

}


int main()
{

    kopiec[0]=1000005;
    /*int a,b;
    while(true)
    {
        cout<<"\n\n";
        cin>>a;

        if(a==1) {cin>>b; dodaj(b);}

        if(a==2) cout<<usun();

        if(a==3) for(int i=1; i<=dlugoscKopca; i++) cout<<kopiec[i]<<" ";

    }*/


    cin>>M>>N;

    for(int i=0; i<N; i++)
    {
        cin>>plyty[i].second;
        cin>>plyty[i].first;
    }
    //for(int i=0; i<N; i++){cout<<"Wysokosc: "<<plyty[i].first<<"  Wartosc: "<<plyty[i].second<<"\n";}
    //cout<<"\n\n\n";
    sort(plyty, plyty+N);

    //for(int i=0; i<N; i++){cout<<"Wysokosc: "<<plyty[i].first<<"  Wartosc: "<<plyty[i].second<<"\n";}

    int j=0;
    for(int i=1; i<=M;i++)
    {
        //cout<<"\n\n\nSprawdzanie plyt dla wysokosci: "<<i<<"\n";
        while(plyty[j].first==i)
        {
            //cout<<"test ";
            dodaj(plyty[j].second);
            j++;
            //cout<<"Na kopiec dodano "<<plyty[j-1].second<<". Wysokosc dodanej plyty to: "<<plyty[j-1].first<<"\n";
        }
        //cout<<"\n"<<plyty[j].first<<"\n";
          if(dlugoscKopca>0){wartosc+=usun();}// cout<<"\nNa poklad dodano plyte (na miejsce "<<i<<"), wartosc to  "<<wartosc;}

    }
    //if(dlugoscKopca>0){wartosc+=usun(); cout<<"\nWartosc: "<<wartosc;}

    cout<<wartosc;




}
