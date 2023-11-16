#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define PII pair<int, int>
#define INF 1000000000

struct Node
{
    int distance;
    int city;
    vector<int> path;
};

struct cmp
{
	bool operator()(Node a, Node b)
	{
        return a.distance > b.distance;
	}
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<PII>> buses(n+1, vector<PII>());
    vector<int> dist(n+1, INF);

    for(int i = 0; i < m; i++)
    {
        int start, dest, weight;
        cin >> start >> dest >> weight;

        buses[start].emplace_back(dest, weight);
    }

    int start, dest;
    cin >> start >> dest;

    priority_queue<Node, vector<Node>, cmp> pq;
    Node starter;
    starter.distance = 0;
    starter.city = start;
    starter.path.push_back(start);

    pq.push(starter);

    vector<int> ans;

    while(!pq.empty())
    {
        Node tmp = pq.top();
        pq.pop();

        int curr_dist = tmp.distance;
        int city = tmp.city;

        if (dist[dest] < curr_dist)
            continue;

        for(int i = 0; i < buses[tmp.city].size(); i++)
        {
            int next_city = buses[tmp.city][i].first;
            int next_dist = curr_dist + buses[tmp.city][i].second;

            if(next_dist < dist[next_city])
            {
                dist[next_city] = next_dist;

                if (next_city == dest)
                    ans = tmp.path;

                Node next_node;
                next_node.distance = next_dist;
                next_node.city = next_city;
                next_node.path = tmp.path;
                next_node.path.push_back(next_city);

                pq.push(next_node);
            }
        }
    }

    ans.push_back(dest);

    cout << dist[dest] << '\n';
    cout << ans.size() << '\n';

    for (const int& c : ans)
        cout << c << ' ';

    return 0;
}