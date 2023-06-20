#include <iostream>

using namespace std;

int arr[10];

int Sum()
{
	int sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + arr[i]) % 1000000000;

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(int i = 1; i < 10; i++)
	{
		arr[i] = 1;
	}

	int N;
	cin >> N;

	for(int i = 1; i < N; i++)
	{
		int tmp[10];
		for(int j = 0; j < 10; j++)
		{
			if (j == 0)
				tmp[j] = arr[1];
			else if (j == 9)
				tmp[j] = arr[8];
			else
				tmp[j] = (arr[j - 1] + arr[j + 1]) % 1000000000;
		}

		for (int j = 0; j < 10; j++)
			arr[j] = tmp[j] % 1000000000;
	}

	cout << Sum();

	return 0;
}