#include <iostream>
#include <algorithm>

#define uint unsigned int


uint arr[10001];

using namespace std;

uint GetCount(uint N, uint K)
{
	uint sum = 0;
	for(uint i = 0; i < K; i++)
	{
		sum += (arr[i] / N);
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	uint K, N;
	cin >> K >> N;

	for (uint i = 0; i < K; i++)
		cin >> arr[i];

	sort(arr, arr + K);

	uint low = 1, high = arr[K-1]+1;

	while(low + 1 < high)
	{
		uint mid = (low + high) / 2;

		if (GetCount(mid, K) < N)
			high = mid;
		else
			low = mid;
	}

	cout << low;


	return 0;
}