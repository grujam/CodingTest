#include <string>
#include <vector>
#include <queue>

using namespace std;

int d[20001];
bool visited[20001];
int max_d = 0;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<vector<int>> e(n + 1);
    queue<int> q;

    for (auto ed : edge)
    {
        e[ed[0]].push_back(ed[1]);
        e[ed[1]].push_back(ed[0]);
    }

    q.push(1);
    d[1] = 1;
    visited[1] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int i = 0; i < e[node].size(); i++)
        {
            if (visited[e[node][i]] == false) {
                q.push(e[node][i]);
                visited[e[node][i]] = true;
                d[e[node][i]] = d[node] + 1;
                if (max_d < d[node] + 1)
                    max_d = d[node] + 1;
            }
        }
    }

    for (int i = 1; i < n+1; i++)
    {
        if (d[i] == max_d)
            answer++;
    }

    return answer;
}