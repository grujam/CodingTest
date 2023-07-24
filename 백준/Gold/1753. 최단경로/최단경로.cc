#include <iostream>
#include <vector>
#include <queue>

#define PII pair<int, int>
#define INF 9999999

using namespace std;

int dist[20001];

struct cmp
{
	bool operator()(PII a, PII b)
	{
		return a.second > b.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int V, E;
	cin >> V >> E;

	int start;
	cin >> start;

	for (int i = 1; i < V + 1; i++)
		dist[i] = INF;

	dist[start] = 0;

	vector<vector<PII>> vec(V+1, vector<PII>());

	for(int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		vec[u].emplace_back(v, w);
	}

	priority_queue<PII, vector<PII>, cmp> pq;

	pq.push(PII(start, 0));

	while (!pq.empty())
	{
		PII cur = pq.top();
		pq.pop();

		for(int i = 0; i < vec[cur.first].size(); i++)
		{
			int next = vec[cur.first][i].first;
			int nextDistance = vec[cur.first][i].second + dist[cur.first];

			if(nextDistance < dist[next])
			{
				dist[next] = nextDistance;
				pq.push(PII(next, nextDistance));
			}
		}
	}

	for(int i = 1; i < V+1; i++)
	{
		if (dist[i] == INF)
			cout << "INF";
		else
			cout << dist[i];
		cout << "\n";
	}

	return 0;
}