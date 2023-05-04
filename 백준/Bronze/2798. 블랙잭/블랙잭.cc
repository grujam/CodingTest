#include <iostream>

using namespace std;

int arr[101];

int GetSum(int i, int j, int k)
{
	return arr[i] + arr[j] + arr[k];
}

bool Cmp(int& a, int& b, int& M)
{
	if (b > M)
		return false;
	return abs(M - a) > abs(M - b);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, ans = 0;
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for(int i = 0; i < N-2; i++)
	{
		for(int j = i+1; j < N-1; j++)
		{
			for(int k = j+1; k < N; k++)
			{
				int cnt = GetSum(i, j, k);

				if(Cmp(ans, cnt, M))
					ans = cnt;
			}
		}
	}

	cout << ans;

	return 0;
}