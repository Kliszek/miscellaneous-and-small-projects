#include <iostream>
#define INF 2100000000

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int tab[n];

    for(int i = 0; i < n; i++)
    {
        cin >> tab[i];
    }

    int tempMinCost, tempMinWeight, tempCost, tempWeight;
    int dyn[n][n];
    int weight[n][n];

    weight[0][0] = tab[0];
    dyn[0][0] = 0;

    for(int i = 1; i < n; i++)
    {
        weight[i][i] = tab[i];
        weight[i - 1][i] = tab[i] + tab[i - 1];
        dyn[i][i] = 0;
        dyn[i - 1][i] = weight[i - 1][i];

        for(int j = i - 2; j >= 0; j--)
        {
            tempMinWeight = INF;
            tempMinCost = INF;

            for(int k = 0; k < i - j; k++)
            {
                tempWeight = weight[j][i - k - 1] + weight[i - k][i];
                tempCost = tempWeight + dyn[j][i - k - 1] + dyn[i - k][i];

                if(tempCost < tempMinCost)
                {
                    tempMinCost = tempCost;
                    tempMinWeight = tempWeight;
                }
            }

            weight[j][i] = tempMinWeight;
            dyn[j][i] = tempMinCost;
        }
    }

    cout << dyn[0][n - 1] << '\n';
}
