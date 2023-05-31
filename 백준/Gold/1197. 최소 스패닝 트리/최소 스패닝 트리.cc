#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[10001];
using PII = pair<int, int>;

struct edge
{
	edge(int src, int dest, int weight)
		: src(src), dest(dest), weight(weight)
	{}

	int src;
	int dest;
	int weight;
};

struct cmp
{
	bool operator()(edge a, edge b)
	{
		return a.weight > b.weight;
	}
};

void addEdges(const vector<vector<PII>>& edges, priority_queue<edge, vector<edge>, cmp>& pq, int idx)
{
	visited[idx] = true;

	for(int i = 0; i < edges[idx].size(); i++)
	{
		if (visited[edges[idx][i].first] == true)
			continue;

		pq.push(edge(idx, edges[idx][i].first, edges[idx][i].second));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int V, E, total = 0;

	cin >> V >> E;

	vector<vector<PII>> edges(V + 1);
	priority_queue <edge, vector<edge>, cmp> pq;

	for(int i = 0; i < E; i++)
	{
		int src, dest, weight;
		cin >> src >> dest >> weight;

		edges[src].emplace_back(dest, weight);
		edges[dest].emplace_back(src, weight);
	}

	addEdges(edges, pq, 1);

	while(!pq.empty())
	{
		edge cur = pq.top();
		pq.pop();

		if(!visited[cur.dest])
		{
			addEdges(edges, pq, cur.dest);
			total += cur.weight;
		}
	}

	cout << total;

	return 0;
}