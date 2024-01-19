#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool visited[1002];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(N+1, vector<int>());
    vector<int> degrees(N+1, 0);

    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        int before, current;
        cin >> before;
        for(int j = 1; j < num; j++)
        {
            cin >> current;

            edges[before].push_back(current);
            degrees[current]++;
            before = current;
        }
    }

    queue<int> q, ans;

    for(int i = 1; i < N+1; i++)
    {
        if (degrees[i] == 0)
        {
            q.push(i);
            visited[i] = true;
            ans.push(i);
        }
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int i = 0; i < edges[cur].size(); i++)
        {
            if (visited[edges[cur][i]] == true)
                continue;

            if (--degrees[edges[cur][i]] == 0)
            {
                q.push(edges[cur][i]);
                ans.push(edges[cur][i]);
            }
        }
    }

    if(ans.size() == N)
    {
	    while(!ans.empty())
	    {
            cout << ans.front() << '\n';
            ans.pop();
	    }
    }
    else
    {
        cout << 0;
    }

    return 0;
}
