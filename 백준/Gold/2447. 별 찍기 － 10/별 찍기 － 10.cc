#include <iostream>

using namespace std;

char arr[2187][2187];

void Print(int x, int y, int N)
{
	N /= 3;

	if(N == 1)
	{
		for (int i = x; i < x + 3; i++)
			for (int j = y; j < y + 3; j++)
				arr[i][j] = '*';
		arr[x + 1][y + 1] = ' ';
		return;
	}

	for(int i = x + N; i < x + 2*N; i++)
		for (int j = y + N; j < y + 2 * N; j++)
			arr[i][j] = ' ';

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)
				continue;
			Print(x + (N*i), y + (N*j), N);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	Print(0, 0, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j];
		}
		cout << "\n";
	}
		

	return 0;
}