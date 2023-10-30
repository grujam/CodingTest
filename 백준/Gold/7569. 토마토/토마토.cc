#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define TIIII tuple<int, int, int, int>

int N, M, H, answer;

int Tomatoes[101][101][101];

int dirx[6] = { 0, -1, 0, 1, 0, 0 };
int diry[6] = { -1, 0, 1, 0, 0, 0 };
int dirz[6] = { 0, 0, 0, 0, 1, -1 };

void Rotten(queue<TIIII>& q)
{
	while(!q.empty())
	{
		TIIII tomato = q.front();
		q.pop();

		int x = get<0>(tomato);
		int y = get<1>(tomato);
		int z = get<2>(tomato);
		int cnt = get<3>(tomato);

		answer = max(cnt, answer);

		for (int i = 0; i < 6; i++)
		{
			int newx = x + dirx[i];
			int newy = y + diry[i];
			int newz = z + dirz[i];

			if (newx < 0 || newx >= N || newy < 0 || newy >= M || newz < 0 || newz >= H || Tomatoes[newx][newy][newz] != 0)
				continue;

			Tomatoes[newx][newy][newz] = 1;
			q.emplace(newx, newy, newz, cnt + 1);
		}
	}
	
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> M >> N >> H;

	queue<TIIII> q;

    for(int k = 0; k < H; k++)
    {
	    for(int i = 0; i < N; i++)
	    {
		    for(int j = 0; j < M; j++)
		    {
				cin >> Tomatoes[i][j][k];

				if (Tomatoes[i][j][k] == 1)
					q.emplace(i, j, k, 0);
					
		    }
	    }
    }

	Rotten(q);

	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (Tomatoes[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << answer;

    return 0;
}