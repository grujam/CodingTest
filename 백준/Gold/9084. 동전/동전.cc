#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int Coins[21];
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    dp[0] = 1;

    for(int i = 0; i < T; i++)
    {
        int N, M;
        cin >> N;
        for(int j = 0; j < N; j++)
            cin >> Coins[j];

        cin >> M;

        for(int k = 1; k <= M; k++)
        {
            if (k % Coins[0] == 0)
                dp[k] = 1;
        }

        for(int j = 1; j < N; j++)
        {
	        for(int k = Coins[j]; k <= M; k++)
	        {
                dp[k] = dp[k] + dp[k - Coins[j]];
	        }
        }
        cout << dp[M] << "\n";
        memset(dp + 1, 0, sizeof(int) * 10000);
    }


    return 0;
}