#include <iostream>
//#define int lon long

using namespace std;

int n, wagonow;


//int o=0;
int okr=0;

//#undef int
int main()
//#define int long long
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    wagonow=n;
    int wagony[n];
int miasta[n];  //zamawiane przez miasta surowce;

for(int i=0; i<n; i++) cin>>wagony[i];

for(int i=0; i<n; i++) cin>>miasta[i];

while(wagonow>0)
{
    for(int i=0; i<n; i++)
    {
        if(wagonow<=0) {if(i>1)okr++; cout<<okr; return 0;}
        //if(i==1) okr++;
        if(miasta[i] == wagony[wagonow-1])
            wagonow--;
        //o++;
        //if(i>=n) o=0;
    }
    okr++;
}


cout<<okr;

}
