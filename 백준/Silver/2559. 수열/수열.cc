#include <iostream>

using namespace std;

int arr[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K;
	cin >> N >> K;

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int sum = 0;

	for(int i = 0; i < K; i++)
	{
		sum += arr[i];
	}

	int ans = sum;

	for(int i = 1; i < N-K+1; i++)
	{
		sum = sum - arr[i - 1] + arr[i + K-1];

		ans = max(sum, ans);
	}

	cout << ans;

	return 0;
}