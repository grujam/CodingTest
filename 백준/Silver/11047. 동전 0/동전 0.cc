#include <iostream>

using namespace std;

int coins[11];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, K, cnt = 0;
	cin >> N >> K;

	for(int i = N-1; i > -1; i--)
	{
		cin >> coins[i];
	}

	for(int i = 0; i < N; i++)
	{
		if (K == 0)
			break;

		cnt += K / coins[i];

		K %= coins[i];
	}

	cout << cnt;

	
	return 0;
}