#include <iostream>
#include <queue>

#define PII pair<int,int>
#define INF 2147483647

using namespace std;


struct cmp
{
	bool operator()(PII a, PII b)
	{
		return a.second > b.second;
	}
};

void Dijkstra(int n, vector<int>& dist, vector<vector<PII>>& v)
{
	priority_queue<PII, vector<PII>, cmp> pq;

	pq.push(PII(n, 0));

	while(!pq.empty())
	{
		int currentNode = pq.top().first;
		int currentDist = pq.top().second;
		pq.pop();

		if (dist[currentNode] < currentDist)
			continue;

		for(int i = 0; i < v[currentNode].size(); i++)
		{
			int nextNode = v[currentNode][i].first;
			int nextNodeDist = v[currentNode][i].second + currentDist;

			if (dist[nextNode] > nextNodeDist)
			{
				dist[nextNode] = nextNodeDist;
				pq.push(PII(nextNode, nextNodeDist));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	vector<vector<PII>> v(N + 1);
	vector<int> dist(N + 1, INF);

	int start, dest, weight;
	for(int i = 0; i < M; i++)
	{
		cin >> start >> dest >> weight;
		v[start].emplace_back(dest, weight);
	}

	cin >> start >> dest;

	dist[start] = 0;
	Dijkstra(start, dist, v);

	cout << dist[dest];

	return 0;
}