#include <iostream>

using namespace std;

int arr[100001];
int dp[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];

	int mx = dp[0];

	for(int i = 1; i < N; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] + arr[i]);
		mx = max(mx, dp[i]);
	}

	cout << mx;

	return 0;
}