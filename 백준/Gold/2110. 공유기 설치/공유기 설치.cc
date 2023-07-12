#include <iostream>
#include <algorithm>

using namespace std;

int arr[200001];

bool Check(const int& n, const int& N, const int& C)
{
	int cnt = 1, cur = 0;

	for (int j = 0; j < N; j++)
	{
		if (arr[j] - arr[cur] >= n)
		{
			cnt++;
			cur = j;
		}

		if (cnt >= C)
			return true;
	}

	return false;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, C;
	cin >> N >> C;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int low = 1, high = arr[N - 1] - arr[0]+1;

	while(low + 1 < high)
	{
		int mid = (high + low) / 2;

		if (Check(mid, N, C))
			low = mid;
		else
			high = mid;
	}

	cout << low;

	return 0;
}