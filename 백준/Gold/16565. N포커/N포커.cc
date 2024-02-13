#include <iostream>

using namespace std;

long long MOD = 10007;

int nCr[53][53];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i <= 52; i++)
    {
        nCr[i][0] = 1;
        nCr[i][i] = 1;
	    for(int j = 1; j < i; j++)
	    {
            nCr[i][j] = nCr[i - 1][j] + nCr[i - 1][j - 1];
            nCr[i][j] %= MOD;
            nCr[i][i - j] = nCr[i][j];
	    }
    }

    int ans = 0;

    for(int i = 4; i <= N; i += 4)
    {
	    if((i / 4) % 2 == 1)
	    {
            ans += nCr[13][i / 4] * nCr[52 - i][N - i];
	    }
        else
        {
            ans -= nCr[13][i / 4] * nCr[52 - i][N - i];
        }
        ans %= MOD;
    }

    ans = (ans + MOD) % MOD;

    cout << ans;

    return 0;
}
