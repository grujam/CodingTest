#include <iostream>

using namespace std;

enum
{
	BLACK, WHITE
};

int white[2000][2000];
int black[2000][2000];
int chess[2000][2000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M, K;
	cin >> N >> M >> K;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			char c;
			cin >> c;

			switch(c)
			{
			case 'B':
				chess[i][j] = BLACK;
				break;
			case 'W':
				chess[i][j] = WHITE;
			}

			if(i % 2 == j % 2)
			{
				if (chess[i][j] == BLACK)
					white[i][j]++;
				else
					black[i][j]++;
			}
			else
			{
				if (chess[i][j] == BLACK)
					black[i][j]++;
				else
					white[i][j]++;
			}
		}
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 1; j < M; j++)
		{
			white[i][j] += white[i][j - 1];
			black[i][j] += black[i][j - 1];
		}
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			white[i][j] += white[i - 1][j];
			black[i][j] += black[i-1][j];
		}
	}

	int ans = 2147483647;

	for(int i = K-1; i < N; i++)
	{
		for(int j = K-1; j < M; j++)
		{
			if (i - K+1 > 0 && j - K+1 > 0)
				ans = min(min(ans, white[i][j] + white[i - K][j - K] - white[i - K][j] - white[i][j - K]), black[i][j] + black[i - K][j - K] - black[i - K][j] - black[i][j - K]);
			else if (i - K+1 == 0 && j - K+1 == 0)
				ans = min(min(ans, white[i][j]), black[i][j]);
			else if (i - K+1 == 0)
				ans = min(min(ans, white[i][j] - white[i][j - K]), black[i][j] - black[i][j - K]);
			else if (j - K+1 == 0)
				ans = min(min(ans, white[i][j] - white[i-K][j]), black[i][j] - black[i-K][j]);
		}
	}

	cout << ans;

	return 0;
}