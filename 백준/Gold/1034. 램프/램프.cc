#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int lamp[51][51];

	int N, M, K, ans = 0;

	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		for(int j = 0; j < M; j++)
		{
			lamp[i][j] = str[j] - '0';
		}
	}

	cin >> K;

	if(N == 1)
	{
		int cnt = 0;
		for (int i = 0; i < M; i++)
			if (lamp[0][i] == 0)
				cnt++;

		if (cnt <= K && K % 2 == cnt % 2)
			cout << 1;
		else
			cout << 0;

		return 0;
	}

	for(int i = 0; i < N; i++)
	{
		int zeros = 0;
		int cnt = 0;

		for(int j = 0; j < M; j++)
		{
			if (lamp[i][j] == 0)
				zeros++;
		}

		if (zeros > K)
			continue;

		if(K % 2 == zeros % 2)
		{
			for (int j = 0; j < N; j++)
			{
				bool check = true;

				for (int k = 0; k < M; k++)
				{
					if (lamp[i][k] != lamp[j][k])
					{
						check = false;
						break;
					}
				}

				if (check)
					cnt++;
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans;



	return 0;
}