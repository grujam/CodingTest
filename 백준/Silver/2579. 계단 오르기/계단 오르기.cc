#include <iostream>

using namespace std;

int dp[301];
int stairs[301];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for(int i = 1; i < N+1; i++)
	{
		cin >> stairs[i];
	}

	dp[1] = stairs[1];
	dp[2] = stairs[1] + stairs[2];
	dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

	for(int i = 4; i < N+1; i++)
	{
		dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i] + stairs[i-1]);
	}

	cout << dp[N];


	return 0;
}