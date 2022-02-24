#include <iostream>


using namespace std;





long long t=0;

int n;
string str;
bool b=true;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie(0);
    cin>>n;


    for(int i=0; i<n; i++)
    {
        cin>>str;
        b=true;
        t=0;
        for(int j=0; j<str.size(); j++)
        {
            if(str[j]=='(') t++;
            else if(str[j]==')') t--;
            else {b=false; break;}
            if(t<0) {b=false; break;}
        }
        if(b && t==0) cout<<"TRUE\n";
        else cout<<"FALSE\n";
    }

}
