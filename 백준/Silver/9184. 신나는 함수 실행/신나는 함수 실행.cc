#include <iostream>

using namespace std;

int dp[21][21][21];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	if (dp[a][b][c] != 0)
		return dp[a][b][c];

	if (a > 20 || b > 20 || c > 20)
	{
		dp[20][20][20] = w(20, 20, 20);
		return dp[20][20][20];
	}

	if(a < b && b < c)
	{
		dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return dp[a][b][c];
	}

	dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return dp[a][b][c];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	for(int i = 0; i < 21; i++)
	{
		dp[0][0][i] = 1;
		dp[0][i][0] = 1;
		dp[i][0][0] = 1;
		dp[0][i][i] = 1;
		dp[i][0][i] = 1;
		dp[i][i][0] = 1;
	}

	while(true)
	{
		cin >> a >> b >> c;
		int ans = 0;

		if (a == -1 && b == -1 && c == -1)
			break;
		if (a <= 0 || b <= 0 || c <= 0)
			ans = 1;
		else if (a > 20 || b > 20 || c > 20)
			ans = w(20, 20, 20);
		else
			ans = w(a, b, c);

		printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
	}


	return 0;
}