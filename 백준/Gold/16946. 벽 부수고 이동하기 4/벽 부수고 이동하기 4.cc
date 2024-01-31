#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>

#define PII pair<int, int>

using namespace std;

int arr[1001][1001];
int dp[1001][1001][2];
bool visited[1001][1001];

int N, M;

int dirx[4] = { 0, -1, 0, 1 };
int diry[4] = { -1, 0 , 1, 0 };

queue<PII> q;

int DFS(int x, int y, int count)
{
	q.emplace(x, y);
	count++;
	visited[x][y] = true;

	for(int i = 0; i < 4; i++)
	{
		int newx = x + dirx[i];
		int newy = y + diry[i];

		if (newx >= N || newy >= M || newx < 0 || newy < 0 || visited[newx][newy] == true || arr[newx][newy] == -1)
			continue;

		count = DFS(newx, newy, count);
	}

	return count;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
	    for(int j = 0; j < M; j++)
	    {
			char c;
			cin >> c;
			if (c == '1')
				arr[i][j] = -1;
			else
				arr[i][j] = c - 48;
	    }
    }
	int count = 0;
    for(int i = 0; i < N; i++)
    {
	    for(int j = 0; j < M; j++)
	    {
			if (arr[i][j] == 0 && visited[i][j] == false)
			{
				int num = DFS(i, j, 0);

				while(!q.empty())
				{
					PII cur = q.front();
					q.pop();
					dp[cur.first][cur.second][0] = num;
					dp[cur.first][cur.second][1] = count;
				}
				count++;
			}
	    }
    }

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				cout << 0;
			else
			{
				int num = 1;
				unordered_map<int, int> um;

				for(int k = 0; k < 4; k++)
				{
					int newx = i + dirx[k];
					int newy = j + diry[k];

					if (newx >= N || newy >= M || newx < 0 || newy < 0 || arr[newx][newy] == -1 || um[dp[newx][newy][1]] > 0)
						continue;

					num += dp[newx][newy][0];
					um[dp[newx][newy][1]]++;
				}
				cout << num % 10;
			}
		}
		cout << '\n';
	}

    return 0;
}
