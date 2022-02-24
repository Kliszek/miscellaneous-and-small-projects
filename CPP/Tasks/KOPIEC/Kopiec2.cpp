#include <iostream>
#include <algorithm>
//#include <queue>

using namespace std;

//priority_queue <int> kopiec;

int kopiec[1000005];
int dlugoscKopca=0;

int M,N;

pair <int, int> plyty[1000005];


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
    kopiec[0]=2000000003;
    cin>>M>>N;

    for(int i=0; i<N; i++) {cin>>plyty[i].second; cin>>plyty[i].first;}

    sort(plyty, plyty+N);


    int nrPlyty=0;
    int wartosc=0;
    for(int i=1; i<=M; i++)
    {

        while(plyty[nrPlyty].first==i)
        {
            dodaj(plyty[nrPlyty].second);
            nrPlyty++;
        }

        //cout<<"Dlugosc kolejki: "<<kopiec.size();

        //cout<<"\nDodano "<<kopiec.top()<<"\n";
        if(dlugoscKopca>0){wartosc+=usun();}



    }

    cout<<wartosc;
}
