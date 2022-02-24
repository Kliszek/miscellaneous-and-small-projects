#include <iostream>
#include <vector>

using namespace std;

vector <int> czynniki;

const int LICZBA = 6578637;
int liczba = 6578637;

int sumaCyfr(int l)
{
    int t=l;
    int suma=0;
    while(t>10)
    {
        suma+=t%10;
        t/=10;
    }
    return suma+t;
}

int Reduktor(int l)
{
    vector <int> czyn;
    int m = 2;
    while(l!=1)
    {
        if(l%m==0)
        {
            czyn.push_back(m);
            l/=m;
        }
        else
        {
            m++;
        }
    }

    int reduktor=0;
    while(!czyn.empty())
    {
        //cout<<czynniki.back()<<" ";

        int t=czyn.back();
        while(t>10)
        {
            reduktor+=t%10;
            t/=10;
        }
        reduktor+=t;
        czyn.pop_back();

    }
    return reduktor;

}

int main()
{
    cout<<"Zad a\nCzynniki: ";
    int m = 2;
    while(liczba!=1)
    {
        if(liczba%m==0)
        {
            czynniki.push_back(m);
            liczba/=m;
        }
        else
        {
            m++;
        }
    }

    int reduktor=0;
    while(!czynniki.empty())
    {
        cout<<czynniki.back()<<" ";

        int t=czynniki.back();
        while(t>10)
        {
            reduktor+=t%10;
            t/=10;
        }
        reduktor+=t;
        czynniki.pop_back();

    }
    cout<<"\nreduktor: "<<reduktor;

    //cout<<"\nReduktor jeszcze raz: "<<Reduktor(LICZBA);

    cout<<"\n\nZad b";
    for(int i=0; i<10; i++)
    {
        int n=0;
        for(int j=10; j<100; j++)
        {
            //to jest oczywiœcie chyba najmniej optymalna metoda, ale co tam
            if(Reduktor(j)==i) n++;
        }
        cout<<"\nDla r="<<i<<" jest "<<n<<" takich liczb.";
    }

    cout<<"\n\nZad c";
    int w=0;
    for(int i=10; i<1000; i++)
    {
        if(sumaCyfr(i)==Reduktor(i)) w++;
    }

    cout<<"\nJest "<<w<<" takich liczb.";
}
