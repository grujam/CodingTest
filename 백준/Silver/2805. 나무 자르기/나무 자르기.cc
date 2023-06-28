#include <iostream>
#include <algorithm>

using namespace std;

long long arr[1000001];

long long GetTreeLength(long long n, long long N)
{
	long long sum = 0;
	for(long long i = 0; i < N; i++)
	{
		if (arr[i] < n)
			continue;
		sum += arr[i] - n;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long N, M;
	cin >> N >> M;

	for(long long i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	long long low = 0, high = arr[N - 1];

	while(low + 1 < high)
	{
		long long mid = (low + high) / 2;
		if (GetTreeLength(mid, N) >= M)
			low = mid;
		else
			high = mid;
	}

	cout << low;

	return 0;
}