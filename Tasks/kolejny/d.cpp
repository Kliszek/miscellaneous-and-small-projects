#include <iostream>
#include <math.h>

using namespace std;


int drzewo[131075];

int p, m;

int D[131075][41];

int main()
{
    cin>>p>>m;
    m=m/2;
    int pk = pow(2, p)-1;



    int t;
    for(int i=1; i<=pk; i++)
    {
        cin>>t;
        cin>>drzewo[i];
        drzewo[i]+=t;
        D[i][0]=0;

        if(drzewo[i]>0)
        {
            D[i][1]=drzewo[i];
        }
        else
        {
            D[i][1]=0;
        }
    }





    for(int i=pk; i>pk/2; i--)
    {
        for(int j=2; j<=m; j++)
            D[i][j]=D[i][1];
    }


    for(int i=pk/2; i>0; i--)
    {
        for(int j=2; j<=m; j++)
        {
            int najw=0;

            for(int q=0; q<j; q++)
            {
                if(D[i*2][q]+D[i*2+1][j-q-1]+drzewo[i] > najw) najw=D[i*2][q]+D[i*2+1][j-q-1]+drzewo[i];
            }
            if(D[i][j-1]>najw) D[i][j]=D[i][j-1];
            else D[i][j]=najw;
        }

    }

    cout<<D[1][m];
    /*cout<<"\n\n";
    for(int i =1; i<=pk; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout <<D[i][j]<<" ";
        }
        cout<<"\n";
    }*/
}
