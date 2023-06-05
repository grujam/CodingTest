#include <iostream>

using namespace std;

int arr[51];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	if (N == 1)
	{
		cout << "A";
		return 0;
	}
	else if (N == 2 && arr[0] != arr[1])
	{
		cout << "A";
		return 0;
	}
	else if (N == 2)
	{
		cout << arr[0];
		return 0;
	}
	else if(arr[1] == arr[0])
	{
		for(int i = 2; i < N; i++)
		{
			if(arr[i] != arr[0])
			{
				cout << "B";
				return 0;
			}
		}
		cout << arr[1];
		return 0;
	}
	int a, b;

	a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
	b = arr[1] - (arr[0] * a);

	for (int i = 1; i < N; i++)
	{
		if (arr[i-1] * a + b != arr[i])
		{
			cout << "B";
			return 0;
		}
	}

	cout << arr[N - 1] * a + b;

	return 0;
}