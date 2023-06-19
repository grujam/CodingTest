#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
char arr[51][51];

int CheckWhiteStart(int x, int y)
{
	int cnt = 0;
	for(int i = x; i < x+8; i++)
	{
		for(int j = y; j < y+8; j++)
		{
			if(i % 2 == 0)
			{
				if (j % 2 == 0 && arr[i][j] == 'B')
					cnt++;
				else if (j % 2 == 1 && arr[i][j] == 'W')
					cnt++;
			}
			else
			{
				if (j % 2 == 0 && arr[i][j] == 'W')
					cnt++;
				else if (j % 2 == 1 && arr[i][j] == 'B')
					cnt++;
			}
		}
	}

	return cnt;
}

int CheckBlackStart(int x, int y)
{
	int cnt = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0 && arr[i][j] == 'W')
					cnt++;
				else if (j % 2 == 1 && arr[i][j] == 'B')
					cnt++;
			}
			else
			{
				if (j % 2 == 0 && arr[i][j] == 'B')
					cnt++;
				else if (j % 2 == 1 && arr[i][j] == 'W')
					cnt++;
			}
		}
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	int cnt = 32;

	for(int i = 0; i < N-7; i++)
	{
		for(int j = 0; j < M-7; j++)
		{
			cnt = min(min(cnt, CheckWhiteStart(i, j)), CheckBlackStart(i, j));
		}
	}

	cout << cnt;

	return 0;
}