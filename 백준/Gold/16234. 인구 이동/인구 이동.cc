#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define PII pair<int,int>

using namespace std;

bool visited[50][50];

int N, L, R;
int dirx[4] = { 0,1,0,-1 };
int diry[4] = { 1,0,-1,0 };

int BFS(int x, int y, vector<vector<int>>& v, vector<PII>& countries)
{
	queue<PII> q;
	int total = 0;

	q.push(PII(x, y));
	countries.emplace_back(x, y);
	total += v[x][y];

	while(!q.empty())
	{
		PII cur = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int newx = cur.first + dirx[i];
			int newy = cur.second + diry[i];
			

			if (newx < 0 || newx > N - 1 || newy < 0 || newy > N - 1 || visited[newx][newy] == true)
				continue;

			int diff = abs(v[newx][newy] - v[cur.first][cur.second]);

			if(diff >= L && diff <= R)
			{
				q.push(PII(newx, newy));
				countries.emplace_back(newx, newy);
				visited[newx][newy] = true;
				total += v[newx][newy];
			}
		}
	}

	return total;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int cnt = 0;
	cin >> N >> L >> R;

	vector<vector<int>> v(N, vector<int>(N, 0));
	vector<PII> countries;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> v[i][j];

	bool check = true;
	while(check)
	{
		check = false;
		memset(visited, false, sizeof(bool) * 50 * 50);

		for(int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				countries.clear();

				if (visited[i][j] == true)
					continue;
				visited[i][j] = true;

				int total = BFS(i, j, v, countries);

				if(countries.size() > 1)
				{
					total /= countries.size();
					check = true;

					for(PII& pii : countries)
					{
						v[pii.first][pii.second] = total;
					}
				}
			}
		}

		cnt++;
	}

	cout << cnt-1;

	return 0;
}