#include <iostream>
#include <queue>

using namespace std;


#define int long long
int n, k;


priority_queue<int, vector<int>, greater<int> > kolejka;

#undef int
int main()
{
    ios_base::sync_with_stdio(false);
#define int long long
    cin>>n>>k;


    int suma=0;
    int t;

    for(int i=0; i<k; i++)
    {
        cin>>t;
        suma+=t;
        kolejka.push(t);
        cout<<suma<<" ";
    }




    for(int i=k; i<n; i++)
    {
        cin>>t;


        if(t>kolejka.top())
        {
            suma+=t;
            kolejka.push(t);
            suma-=kolejka.top();
            kolejka.pop();
        }
        cout<<suma<<" ";
    }

}
