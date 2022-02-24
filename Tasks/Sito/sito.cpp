#include <iostream>


using namespace std;


int n;
bool A[1299710];


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);

    cin>>n;


    //bool A[n+1];
    for(int i=0; i<1299711; i++)
    {
        A[i]=true;
    }


    for(int i=2; i*i<=1299711; i++)
    {

        if(A[i])
        {

            for(int j=i*i; j<=1299711; j+=i)
            {
                A[j]=false;


            }


        }


    }

    int k=0;
    for(int i=2; k<n; i++)
    {
        if(A[i]) {cout<<i<<" "; k++;}
    }

}
