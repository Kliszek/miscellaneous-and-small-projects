#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define PB push_back
#define ST first
#define ND second
#define PF push_front
#define MP make_pair

int tab[1000000];

int main()
    {
    int n,k;
    scanf("%d %d",&n,&k);
    int ile=2;
    int pos=1;
    VPII zak;
    REP(x,n)
        {
        int a=pos;
        REP(y,ile)
            {
            scanf("%d",&tab[pos++]);
            }
        int b=pos-1;
        zak.PB(MP(a,b));
        ile*=2;
        }

    PII edek=zak.back();
        zak.pop_back();

        int zz=0;

        int ile2=(edek.ND-edek.ST+1)/2;
        int wyn[ile2][k+1];
        REP(x,ile2)
            {
            REP(y,k+1)
                {
                if (y<2)
                    {
                    wyn[x][y]=0;
                    }
                else
                    {
                    int co=tab[edek.ST+zz]+tab[edek.ST+zz+1];
                    int obl=0;
                    if (y>0)
                        {
                        obl=max(obl,wyn[x][y-1]);
                        }
                    int ile3=co;
                    int wyk=obl;
                    REP(z,y-1)
                        {
                        wyk=max(wyk,ile3);
                        }
                    wyn[x][y]=wyk;
                    }
                }
            zz+=2;
            }

    while(!zak.empty())
        {
        PII edek=zak.back();
        zak.pop_back();

        int zz=0;

        int ile2=(edek.ND-edek.ST+1)/2;
        int wyn2[ile2][k+1];;
        REP(x,ile2)
            {
            REP(y,k+1)
                {
                if (y<2)
                    {
                    wyn2[x][y]=0;
                    }
                else
                    {
                    int co=tab[edek.ST+zz]+tab[edek.ST+zz+1];
                    int obl=0;
                    if (y>0)
                        {
                        obl=max(obl,wyn2[x][y-1]);
                        }
                    int ile3=co;
                    int wyk=obl;
                    REP(z,y-1)
                        {
                        wyk=max(wyk,wyn[zz][z]+wyn[zz+1][y-2-z]+ile3);
                        }
                    wyn2[x][y]=wyk;
                    }
                }
            zz+=2;
            }
        REP(x,ile2)
            {
            REP(y,k+1)
                {
                wyn[x][y]=wyn2[x][y];
                }
            }
        }
    printf("%d\n",wyn[0][k]);
    return 0;
    }
