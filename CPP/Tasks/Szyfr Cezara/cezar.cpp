#include <iostream>

using namespace std;

int n;
string r;
string wyraz;




int main()
{
    //ios_base::sync_with_stdio(false);
    cin>>r;

    cin>>n;
    if(r[0]=='s') n*=(-1);

    getline(cin, wyraz);
    getline(cin, wyraz);


    int a;
    //cout<<"\nLitera to: "<<alfabet[25].second+65<<"\n";
    for(int i=0; i<wyraz.size(); i++)
    {
        a= wyraz[i];
        if(a>=65 && a<=90)
        {
            a= wyraz[i]-n;
            if(a<65) a+=26;
            if(a>90) a-=26;
        }
        else if(a>=97 && a<=122)
        {
            a= wyraz[i]-n;
            if(a<97) a+=26;
            if(a>122) a-=26;
        }
        cout<<(char)a;
    }

}


