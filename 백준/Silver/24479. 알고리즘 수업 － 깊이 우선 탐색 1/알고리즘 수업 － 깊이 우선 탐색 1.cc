#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100002];
int VisitOrder[100002];
int cnt = 1;

void dfs(int src, vector<vector<int>>& v)
{
	VisitOrder[src] = cnt++;
	visited[src] = true;

	for (int i = 0; (unsigned int)i < v[src].size(); i++)
	{
		if (visited[v[src][i]] == false)
			dfs(v[src][i], v);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, R;

	cin >> N >> M >> R;

	vector<vector<int>> v(N+1, vector<int>());



	for (int i = 1; i < M+1; i++)
	{
		int src, dest;

		cin >> src >> dest;

		v[src].push_back(dest);
		v[dest].push_back(src);
	}

	for (int i = 1; i < N+1; i++)
	{
		sort(v[i].begin(), v[i].end());
	}

	dfs(R, v);

	for (int i = 1; i < N + 1; i++)
	{
		cout << VisitOrder[i] << "\n";
	}

	return 0;
}