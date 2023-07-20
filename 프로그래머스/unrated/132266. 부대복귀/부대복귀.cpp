#include <string>
#include <vector>
#include <queue>

#define INF 100001

using namespace std;

int dist[100001];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    vector<vector<int>> edges(n + 1, vector<int>());
    queue<int> q;

    for (vector<int>& v : roads)
    {
        edges[v[0]].emplace_back(v[1]);
        edges[v[1]].emplace_back(v[0]);
    }

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[destination] = 0;

    q.push(destination);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        int distance = dist[node];

        for (int i = 0; i < edges[node].size(); i++)
        {
            int next = edges[node][i];
            int nextDistance = distance + 1;

            if (dist[next] > nextDistance)
            {
                dist[next] = nextDistance;
                q.push(next);
            }
        }
    }

    for (int i = 0; i < sources.size(); i++)
    {
        if(dist[sources[i]] == INF)
            answer.emplace_back(-1);
        else
            answer.emplace_back(dist[sources[i]]);
    }

    return answer;
}