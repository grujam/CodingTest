#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

int arr[1000001];

void Arrange(int i, int idx)
{
	for(int n = idx; n > i; n--)
	{
		int tmp = arr[n];
		arr[n] = arr[n - 1];
		arr[n - 1] = tmp;
	}
}

void Sort(int cnt, int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		if (cnt == 0)
			return;

		int mx = arr[i];
		int idx = i;

		for (int j = i; j < N && j <= cnt + i; j++)
		{
			if (arr[j] > mx)
			{
				idx = j;
				mx = arr[j];
			}
		}

		if (idx != i)
		{
			Arrange(i, idx);

			cnt -= (idx - i);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, A;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cin >> A;

	Sort(A, N);

	for(int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}