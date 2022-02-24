#include <iostream>
#include <stack>

using namespace std;

stack <int> stos;

int n;
int d=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    string t;
    int a;

    for(int i=0; i<n; i++)
    {
        cin>>t;
        if(t=="+")
        {
            cin>>a;
            stos.push(a-d);
        }

        else if(t=="-")
        {
            cout<<stos.top()+d<<"\n";
            stos.pop();
        }

        else
        {
            cin>>a;
            d+=a;
        }
    }


}
