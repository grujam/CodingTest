#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int students[100001];
bool visited[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        int N, ans;
        cin >> N;

        ans = N;

        for (int i = 1; i < N+1; i++)
            cin >> students[i];

        memset(visited, false, sizeof(visited));

        for(int i = 1; i < N+1; i++)
        {
            if(visited[i])
                continue;

            queue<int> q;
            int cur = students[i];

            visited[i] = true;
            q.push(i);

	        while(visited[cur] == false)
	        {
                q.push(cur);
                visited[cur] = true;
                cur = students[cur];
	        }

            while(!q.empty())
            {
                int front = q.front();
                if (front == cur)
                    break;
                q.pop();
            }
            ans -= q.size();
        }

        cout << ans << '\n';
    }

    return 0;
}
