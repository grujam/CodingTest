#include <iostream>
#include <algorithm>

using namespace std;

int C, N;

int cost[21];
int customer[21];

int dp[100001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> C >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> cost[i] >> customer[i];
	}

	for(int i = 0; i < 100001; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if (cost[j] > i)
				continue;

			if (i - cost[j] > -1)
				dp[i] = max(dp[i - cost[j]] + customer[j], dp[i]); 
		}

		if(dp[i] >= C)
		{
			cout << i;
			break;
		}
	}

	return 0;
}