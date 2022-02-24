#include <iostream>
#include <set>

//#define begin rbegin
//#define rbegin rbegin

using namespace std;

multiset <long long> sp;
multiset <long long> ss;
multiset <long long> sk;

int main ()
{
    ios_base::sync_with_stdio(0);
    //long long sup=0, sus=0, suk=0;
    long long n;
    cin >> n;
    long long ile=0;
    long long suma=0;
    sp.insert (0);
    sk.insert (20000000);

    for (long long x,y,i=0; i<n; i++)
    {
        cin >> x;
        if (x==1)
        {
            ile++;
            cin>>y;
            if (y< *sp.rbegin() )
            {
                auto ptr = sp.end();
                ptr--;
                sp.insert(y);
                ss.insert (*sp.rbegin() );
                suma+=*sp.rbegin();
                sp.erase(ptr );
            }
            else if (y>*sp.begin() )
            {
                sk.insert(y);
                ss.insert (*sk.begin() );
                suma+=*sk.begin();
                sk.erase(sk.begin() );
            }
            else
            {
                ss.insert (y);
                suma+=y;
            }
            if (ile%10==0)
            {
                auto ptr = ss.end();
                ptr--;
                suma -= (*ss.begin() );
                suma -= (*ss.rbegin() );
                ////////////////////////////////////////////////////////////////////
                sp.insert (*ss.begin() );
                sk.insert (*ss.rbegin() );
                ss.erase (ss.begin() );
                ss.erase (ptr );
                ///////////////////////////////////////////////
            }
        }
        else
        {
            cout << suma << "/"<<ile-((ile/10)*2)<<endl;
        }

    }
}
