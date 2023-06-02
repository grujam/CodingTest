#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dp[1001][3];
int houses[1001][3];

int Least(int a, int b, int c)
{
	int num = min(a, b);
	num = min(num, c);
	return num;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> houses[i][0] >> houses[i][1] >> houses[i][2];

	dp[1][0] = min(houses[0][1] + houses[1][0], houses[0][2] + houses[1][0]);
	dp[1][1] = min(houses[0][0] + houses[1][1], houses[0][2] + houses[1][1]);
	dp[1][2] = min(houses[0][0] + houses[1][2], houses[0][1] + houses[1][2]);

	for(int i = 2; i < N; i++)
	{
		dp[i][0] = min(dp[i - 1][1] + houses[i][0], dp[i - 1][2] + houses[i][0]);
		dp[i][1] = min(dp[i - 1][0] + houses[i][1], dp[i - 1][2] + houses[i][1]);
		dp[i][2] = min(dp[i - 1][0] + houses[i][2], dp[i - 1][1] + houses[i][2]);
	}

	cout << Least(dp[N-1][0], dp[N-1][1], dp[N-1][2]);

	return 0;
}