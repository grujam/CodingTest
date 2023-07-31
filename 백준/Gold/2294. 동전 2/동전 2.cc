#include <iostream>
#include <cstring>

#define INF 9999999

using namespace std;

int Value[10001];
int Coins[100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
        cin >> Coins[i];

    for (int i = 0; i <= k; i++)
    {
        if (i % Coins[0] == 0)
            Value[i] = i / Coins[0];
        else
            Value[i] = INF;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (j < Coins[i])
                continue;

            if (j == Coins[i])
            {
                Value[j] = 1;
                continue;
            }

            Value[j] = min(Value[j], Value[j - Coins[i]] + 1);
        }
    }

    if (Value[k] == INF)
        cout << "-1";
    else
        cout << Value[k];

    return 0;
}