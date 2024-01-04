#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int degree[32001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(N+1, vector<int>());

    for(int i = 0; i < M; i++)
    {
        int start, dest;
        cin >> start >> dest;

        edges[start].push_back(dest);
        degree[dest]++;
    }

    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 1; i < N+1; i++)
    {
        if (degree[i] == 0)
            pq.push(i);
    }

    while(!pq.empty())
    {
        int cur = pq.top();
        pq.pop();

        cout << cur << ' ';

        for(int i = 0; i < edges[cur].size(); i++)
        {
            if (--degree[edges[cur][i]] == 0)
                pq.push(edges[cur][i]);
        }
    }

    return 0;
}
