#include <iostream>

using namespace std;

long long Count(long long mid, long long N)
{
	long long cnt = 0;
	for(long long i = 1; i <= N; i++)
	{
		cnt += min(mid/i, N);
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long N, K;
	cin >> N >> K;

	K = min((long long)1000000000, K);

	long long low = 0, high = N*N;

	while(low +1 < high)
	{
		long long mid = (low + high) / 2;

		if (Count(mid, N) < K)
			low = mid;
		else
			high = mid;
	}

	cout << high;

	return 0;
}