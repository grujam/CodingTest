#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

bool visited[100001];

void dfs(int src, vector<vector<int>>& v)
{
	visited[src] = true;
	cout << src << " ";

	for(int s : v[src])
	{
		if (visited[s] == false)
			dfs(s, v);
	}
}

void bfs(int src, vector<vector<int>>& v)
{
	queue<int> q;

	q.push(src);
	visited[src] = true;

	while(!q.empty())
	{
		int newsrc = q.front();
		q.pop();

		cout << newsrc << " ";

		for(int s : v[newsrc])
		{
			if(visited[s] == false)
			{
				visited[s] = true;
				q.push(s);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, V;

	cin >> N >> M >> V;

	vector<vector<int>> v(N + 1, vector<int>());

	for(int i = 0; i < M; i++)
	{
		int src, dest;

		cin >> src >> dest;

		v[src].push_back(dest);
		v[dest].push_back(src);
	}

	for(int i = 1; i < N+1; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	dfs(V, v);
	cout << endl;
	memset(visited, false, sizeof(bool) * N + 1);
	bfs(V, v);


	return 0;
}