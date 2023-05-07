#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[101];
int cnt = -1;

void dfs(int src, vector<vector<int>>& v)
{
	visited[src] = true;
	cnt++;

	for(int dest : v[src])
	{
		if (visited[dest] == false)
			dfs(dest, v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N >> M;

	vector<vector<int>> v(N+1, vector<int>());

	for(int i = 0; i < M; i++)
	{
		int src, dest;

		cin >> src >> dest;

		v[src].push_back(dest);
		v[dest].push_back(src);
	}

	dfs(1, v);

	cout << cnt;


	return 0;
}