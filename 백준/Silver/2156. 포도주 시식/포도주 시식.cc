#include <iostream>
#include <algorithm>

using namespace std;

int wines[10000];
int dp[10000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, ans = 0, idx;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> wines[i];

	dp[0] = wines[0];
	dp[1] = wines[0] + wines[1];
	dp[2] = max(max(wines[0] + wines[2], wines[1] + wines[2]), wines[0] + wines[1]);


	ans = max(max(dp[0], dp[1]), dp[2]);

	for(int i = 3; i < N; i++)
	{
		dp[i] = max(max(dp[i - 2] + wines[i], dp[i - 3] + wines[i - 1] + wines[i]), dp[i-1]);
	}

	cout << dp[N-1];

	return 0;
}