#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

using PII = pair<int, int>;
using TIIIB = tuple<int, int, int, bool>;

int answer = 9999999;
int N, M;

int arr[1001][1001];
int visited[1001][1001];

int dirx[4] = {0, -1, 0, 1};
int diry[4] = {-1, 0, 1, 0};

void BFS()
{
    queue<TIIIB> q;

    q.emplace(0, 0, 1, false);

    while(!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        int bWall = get<3>(q.front());
        q.pop();

        if (cnt >= answer)
            return;

        if(x == N-1 && y == M-1)
        {
            answer = min(answer, cnt);
            return;
        }

		for(int i = 0; i < 4; i++)
        {
            int newx = x + dirx[i];
            int newy = y + diry[i];
            int newbWall = bWall;

            if (newx < 0 || newx > N - 1 || newy < 0 || newy > M - 1)
                continue;

            if (arr[newx][newy] == 1)
            {
                if (newbWall)
                    continue;
                else
                    newbWall = true;
            }

            if (visited[newx][newy] != 0 && newbWall)
                continue;
            if (visited[newx][newy] == -1 && !newbWall)
                continue;

            if (!newbWall)
                visited[newx][newy] = -1;
            else
                visited[newx][newy] = 1;

            q.emplace(newx, newy, cnt + 1, newbWall);
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    vector<PII> v;


	for(int i = 0; i < N; i++)
    {
	    for(int j = 0; j < M; j++)
	    {
            char c;
            cin >> c;
            arr[i][j] = c - 48;
            if (arr[i][j] == 1)
                v.emplace_back(i, j);
	    }
    }

    visited[0][0] = -1;

    BFS();


    if (answer == 9999999)
        cout << -1;
    else
        cout << answer;

    return 0;
}