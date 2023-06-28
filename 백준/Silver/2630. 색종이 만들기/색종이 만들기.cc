#include <iostream>
#include <algorithm>

using namespace std;

int arr[128][128];

int White, Blue;

bool Check(int x, int y, int N)
{
	int check = arr[x][y];
	for(int i = x; i < x + N; i++)
	{
		for(int j = y; j < y + N; j++)
		{
			if (arr[i][j] != check)
				return false;
		}
	}

	if (check == 0)
		White++;
	else
		Blue++;
	return true;
}

void Solution(int x, int y, int N)
{
	int sum = 0;

	if (Check(x, y, N) == false)
	{
		N /= 2;
		Solution(x, y, N);
		Solution(x + N, y, N);
		Solution(x, y + N, N);
		Solution(x + N, y + N, N);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	Solution(0, 0, N);

	cout << White << endl << Blue;

	return 0;
}