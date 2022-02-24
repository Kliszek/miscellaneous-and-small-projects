#include <iostream>
#include <fstream>

using namespace std;

fstream sys1 ("dane_systemy1.txt");
fstream sys2 ("dane_systemy2.txt");
fstream sys3 ("dane_systemy3.txt");

int sys2dec(string a, int sys)
{
    int wyn=0;
    int w=1;
    for(int i=a.size()-1; i>=0; i--)
    {
        wyn+=(a[i]-48)*w;
        w*=sys;
    }
    return wyn;
}

string dec2bin(int a)
{
    if(a==0) return "";
    string wyn="";
    wyn+=dec2bin(a/2);
        if(a%2==1)
            wyn+="1";
        else
            wyn+="0";
    return wyn;
}

void zad1()
{



}

int main()
{
    cout<<sys2dec("01010110", 2)<<"\n";
    cout<<sys2dec("126", 8)<<"\n";
    cout<<sys2dec("86", 10)<<"\n";
    cout<<sys2dec("56", 16)<<"\n";
    cout<<dec2bin(86);

}
