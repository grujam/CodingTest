#include <iostream>

using namespace std;

long long dp[101][10][1024];

#define MOD 1000000000

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i < 10; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    for(int i = 2; i <= N; i++)
    {
	    for(int j = 0; j < 10; j++)
	    {
            for (int k = 1; k < 1024; k++)
            {
                if (j == 0)
                    dp[i][j][k | (1 << j)] += dp[i - 1][j + 1][k] % MOD;
                else if (j == 9)
                    dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % MOD;
                else
                {
                    dp[i][j][k | (1 << j)] += (dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k] ) % MOD;
                }
            }
	    }
    }

    long long ans = 0;
    for(int i = 0; i < 10; i++)
    {
        ans += dp[N][i][1023] % MOD;
    }

    cout << ans % MOD;

    return 0;
}
