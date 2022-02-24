#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

#define MAX_W 30002   //maksymalna liczba miast (wierzcho³ków)


int t1,t2;

//queue <int> kolejka;  //kolejka do BFSa
//int q;                //zmienna do BFSa


struct Wierzcholek
{
    int glebokosc=-1;
    //int ojciec=-1;

    vector <int> sasiedzi;

    vector <int> przodkowie;

    bool odwiedzony = false;    //do DFSa

    int czasWejscia = -1;
    int czasWyjscia = -1;
};

Wierzcholek W[MAX_W];

int wierzcholkow;

int jumpPointerow;

void DFS(int s)
{
    W[s].odwiedzony = true;
    if(W[s].czasWejscia==-1)W[s].czasWejscia=t1++;

    for(int i=1; i<jumpPointerow; i++)    //ten wierzcho³ek ma ju¿ ojca, teraz trzeba wyznaczyæ pozosta³ych przodków
    {
        W[s].przodkowie.push_back(W[ W[s].przodkowie[i-1] ].przodkowie[i-1]);
    }

    //if(W[s].sasiedzi.size() ==1){ W[s].czasWyjscia=t2++;}

    for(int i=0; i< W[s].sasiedzi.size(); i++)
    {
        if( W[ W[s].sasiedzi[i] ].odwiedzony==false)
        {
            W[ W[s].sasiedzi[i] ].glebokosc = W[s].glebokosc + 1;
            W[ W[s].sasiedzi[i] ].przodkowie.push_back(s);
            DFS(W[s].sasiedzi[i]);
        }
    }
    W[s].czasWyjscia=t2++;
}


bool czyJestPrzodkiem(int ww, int pp)
{
    if( W[pp].czasWejscia< W[ww].czasWejscia && W[pp].czasWyjscia> W[ww].czasWyjscia)
        return true;
    return false;
}


int LCA(int w1, int w2)
{
    if( w1 == w2) return w2;
    if( czyJestPrzodkiem(w1, w2)) return w2;
    if( czyJestPrzodkiem(w2, w1)) return w1;

    for(int i=jumpPointerow-1; i>=0; i--)
    {
        if( !czyJestPrzodkiem(w2, W[w1].przodkowie[i]))
        {
            w1= W[w1].przodkowie[i];
        }

    }

    return W[w1].przodkowie[0];

/*    if(w1==w2) return w1;

    if( W[w1].glebokosc == W[w2].glebokosc )
    {


        while(true)
        {
            if(W[w1].przodkowie[0] == W[w2].przodkowie[0]) return W[w1].przodkowie[0];

            int p = 0;
            while( W[w1].przodkowie[p] != W[w2].przodkowie[p] )
            {
                p++;
            }
            w1 = W[w1].przodkowie[p-1];
            w2 = W[w2].przodkowie[p-1];
        }

    }

    else if( W[w1].glebokosc > W[w2].glebokosc)
    {
        while( W[w1].glebokosc != W[w2].glebokosc)
        {
            w1 = W[w1].przodkowie[0];
        }
        return LCA(w1, w2);
    }

    else
    {
        while( W[w1].glebokosc != W[w2].glebokosc)
        {
            w2 = W[w2].przodkowie[0];
        }
        return LCA(w1, w2);
    }
*/
}



int main()
{
    ios_base::sync_with_stdio(false);


    cin>>wierzcholkow;

    //W[1].ojciec=0;
    for(int i=1; i<wierzcholkow; i++)
    {
        cin>>t1>>t2;
        W[t1].sasiedzi.push_back(t2);
        W[t2].sasiedzi.push_back(t1);
    }



    W[1].glebokosc=0;
    //kolejka.push(1);


    jumpPointerow = log2(wierzcholkow);

    for(int i=0; i<jumpPointerow; i++) W[1].przodkowie.push_back(1);

    t1=0;   //czas wejscia
    t2=0;   //czas wyjscia
    DFS(1);
    //=========================================
    //   |- DZIENNIK PROGRAMISTY
    //   |- - - Wpis k


    //MAM JU¯ G£ÊBOKOŒÆ I OJCÓW WSZYSTKICH WIERZCHO£KÓW

    //teraz te g³upie jump pointery
    //k++;
    //
    //
    //
    //
    //-----------------------------------------
    //   |- DZIENNIK PROGRAMISTY
    //   |- - - Wpis k
    //Okej, nareszcie. Ju¿ je ogarn¹³em
    //Co ja robiê




    //      -------       ----           -------------            -------------            -----------\
    //      |  \  \       |  |          | |---------| |          | |---------| |          |-|--------\ \
    //      |  |\  \      |  |          | |         | |          | |         | |          | |         \ \
    //      |  | \  \     |  |          | |         | |          | |         | |          | |         | |
    //      |  |  \  \    |  |          | |         | |          | |         | |          | |         | |
    //      |  |   \  \   |  |          | |         | |          | |         | |          | |_________/ /
    //      |  |    \  \  |  |          | |         | |          | |         | |          | |----------\ \
    //      |  |     \  \ |  |          | |         | |          | |         | |          | |          | |
    //      |  |      \  \|  |          | |         | |          | |         | |          | |          | |
    //      |  |       \  \  |          | |         | |          | |         | |          | |          | |
    //      |  |        \  \ |          | |---------| |          | |---------| |          |-|----------/ /
    //      ----         ----            -------------            -------------            -------------/
    //Ciekawe, czy ktoœ kiedykolwiek zajrzy do tego kodu i to zobaczy, hehe


    //cout<<W[13].przodkowie[0]<<"\n"<<W[13].przodkowie[1]<<"\n"<<W[13].przodkowie[2];   // <==== DZIA£A!!!
    //teraz trzeba napisaæ LCA

    //cout<<W[13].glebokosc<<" "<<W[16].glebokosc<<"\n";


    /*while(true)
    {
        cout<<"\n\n";
        cin>>t1>>t2;
        cout<<"\n"<<LCA(t1,t2);
    }*/


    //LCA DZIA£A!! :D
    //Wszystkie podziêkowania œlê Krzysiowi ;)

    //teraz ju¿ z górki

    //cout<<W[9].czasWejscia<<" "<<W[9].czasWyjscia<<"\n";
    //cout<<czyJestPrzodkiem(21,1);



    int miastDoOdwiedzenia;
    cin>>miastDoOdwiedzenia;
    //int miasta[miastDoOdwiedzenia];


    int aktMiasto;
    cin>>aktMiasto;
    int s = W[aktMiasto].glebokosc;

    for(int i=1; i<miastDoOdwiedzenia; i++)
    {
        cin>>t1;
        s += W[aktMiasto].glebokosc + W[t1].glebokosc - 2* W[LCA(aktMiasto, t1)].glebokosc;
        aktMiasto = t1;
    }

    cout<<s;
}
