#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

bool visited[100001];
int VisitOrder[100001];
int cnt = 1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, R;

	cin >> N >> M >> R;

	vector<vector<int>> v(N+1, vector<int>());

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

	queue<int> q;

	q.push(R);
	visited[R] = true;

	while(!q.empty())
	{
		int src = q.front();
		VisitOrder[src] = cnt++;
		q.pop();

		for(int dest : v[src])
		{
			if(visited[dest] == false)
			{
				visited[dest] = true;
				q.push(dest);
			}
		}
	}

	for(int i = 1; i < N+1; i++)
	{
		cout << VisitOrder[i] << "\n";
	}
	
	return 0;
}