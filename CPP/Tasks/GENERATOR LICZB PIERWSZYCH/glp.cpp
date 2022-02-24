// Generacja n liczb pierwszych
// (C)2010 I LO w Tarnowie
//------------------------

#include <iostream>

using namespace std;

int main()
{
    int n,i,p,lp;
    bool t;

    cin >> n;

    lp = 0;
    p = 2;

    while(lp < n)
    {
        t = true;
        for(i = 2; i < p; i++)
            if(p % i == 0)
            {
                t = false;
                break;
            }

        if(t)
        {
            cout << p << ", ";
            lp++;
        }
        p++;
    }

    cout << endl;

    return 0;
}
