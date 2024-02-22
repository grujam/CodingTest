#include <iostream>
#include <vector>

using namespace std;

int dp[1000001][2];
bool visited[1000001];

void dfs(int node, const vector<vector<int>>& edges)
{
	visited[node] = true;
	dp[node][0] = 1;

	for(int i = 0; i < edges[node].size(); i++)
	{
		int child = edges[node][i];

		if (visited[child])
			continue;

		dfs(child, edges);
		dp[node][1] += dp[child][0];
		dp[node][0] += min(dp[child][1], dp[child][0]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> edges(N + 1, vector<int>());

	for(int i = 0; i < N-1; i++)
	{
		int par, child;
		cin >> par >> child;

		edges[par].push_back(child);
		edges[child].push_back(par);
	}

	dfs(1, edges);

	cout << min(dp[1][1], dp[1][0]);

	return 0;
}