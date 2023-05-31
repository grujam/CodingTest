#include <iostream>

using namespace std;

int arr[100001];
int sum[100001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	cin >> arr[0];
	sum[0] = arr[0];

	for(int i = 1; i < N; i++)
	{
		cin >> arr[i];
		sum[i] = arr[i] + sum[i - 1];
	}

	for(int i = 0; i < M; i++)
	{
		int start, dest, ans = 0;
		cin >> start >> dest;
		if (start == 1)
			ans = sum[dest - 1];
		else
			ans = sum[dest-1] - sum[start - 2];

		cout << ans << "\n";
	}

	return 0;
}