#include <iostream>


using namespace std;




double stos[101];
int R= -1;


double dodaj(double x)
{
    R++;
    stos[R]=x;
    //cout<<"Dodano "<<x<<"\n";
}
double usun()
{
    R--;
    return stos[R+1];
}



int main()
{
    string dzialanie;

    getline(cin, dzialanie);
    //cin>>dzialanie;

    double a=0;
    int przecinek=1;
    bool zmn=false;

    for(int i=0; i<dzialanie.size(); i++)
    {
        if(dzialanie[i]==' ') continue;

        if(zmn) przecinek*=10;
        if(dzialanie[i]=='.') zmn=true;

        if((int)dzialanie[i]>=48 && (int)dzialanie[i]<58)
        {
            a*=10;
            a+=dzialanie[i]-'0';

            if(dzialanie[i+1]==' ')
            {
                dodaj(a/przecinek);
                przecinek=1;
                zmn=false;
                a=0;
            }
            //dodaj(dzialanie[i]-'0');
            //if(!cyfra) {a=(int)dzialanie[i]; cyfra=true;}
            //else {a*=10; a+=(int)dzialanie[i];}
        }

        /*else if(dzialanie[i]==' ' && (int)dzialanie[i-1]>=48 && (int)dzialanie[i-1]<58)
        {
            dodaj(a);
            //cout<<"spacja\n";
        }*/

        else if(dzialanie[i]=='+')
        {
            double m=usun();
            double n=usun();
            dodaj(m+n);
        }
        else if(dzialanie[i]=='-')
        {
            double m=usun();
            double n=usun();
            dodaj(n-m);
        }
        else if(dzialanie[i]=='*')
        {
            double m=usun();
            double n=usun();
            dodaj(m*n);
        }
        else if(dzialanie[i]=='/')
        {
            double m=usun();
            double n=usun();
            dodaj(n/m);
        }
    }
    cout<<stos[0];
}
