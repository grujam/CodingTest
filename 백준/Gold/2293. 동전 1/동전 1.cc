#include <iostream>

using namespace std;

int dp[10001];
int coins[100];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> coins[i];

	for(int i = 1; i < K+1; i++)
	{
		if (i % coins[0] == 0)
			dp[i] = 1;
	}

	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < K+1; j++)
		{
			if (coins[i] > j)
				dp[j] = dp[j];
			else if (coins[i] == j)
				dp[j] = dp[j] + 1;
			else
			{
				dp[j] = dp[j] + dp[j - coins[i]];
			}
		}
	}

	cout << dp[K];

	return 0;
}