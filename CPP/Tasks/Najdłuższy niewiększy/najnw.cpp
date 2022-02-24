#include <iostream>


using namespace std;


#define int long long
int n, k;
int t;
int suma = 0, p = 0;
int najw=0;

#undef int
int main()
{
#define int long long
    ios_base::sync_with_stdio(false);
    cin>>n>>k;

    int tab[n];
    for(int i=0; i<n; i++)
    {
        cin>>t;
        tab[i]=t;

        suma+=t;
        while(suma>k)
        {
            suma-=tab[p];
            p++;
        }
    if (i - p + 1 > najw) najw = i - p + 1;
    }


cout<<najw;


}
