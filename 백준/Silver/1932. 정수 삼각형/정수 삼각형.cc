#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int dp[501][501];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < i+1; j++)
		{
			cin >> arr[i][j];
		}
	}

	dp[0][0] = arr[0][0];

	for(int i = 1; i < N; i++)
	{
		for(int j = 0; j < i+1;j++)
		{
			if(j == 0)
			{
				dp[i][j] = dp[i - 1][j] + arr[i][j];
				continue;
			}
			else if(j == i)
			{
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
				continue;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1] + arr[i][j], dp[i - 1][j] + arr[i][j]);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		ans = max(ans, dp[N - 1][i]);
	}

	cout << ans;

	return 0;
}