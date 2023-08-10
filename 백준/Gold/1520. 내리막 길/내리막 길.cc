#include <iostream>
#include <vector>

using namespace std;

int N, M;

int dirx[4] = { 0, -1, 0, 1 };
int diry[4] = { -1, 0, 1, 0 };

int DFS(int x, int y, vector<vector<int>>& v, vector<vector<int>>& path)
{
    if (path[x][y] > -1)
        return path[x][y];

    path[x][y] = 0;

    for(int i = 0; i < 4; i++)
    {
        int newx = x + dirx[i];
        int newy = y + diry[i];

        if (newx < 0 || newx > N - 1 || newy < 0 || newy > M - 1)
            continue;

        if (v[x][y] <= v[newx][newy] || v[newx][newy] == 0)
            continue;
        
        path[x][y] += DFS(newx, newy, v, path);
    }
	return path[x][y];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<vector<int>> path(N, vector<int>(M, -1));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> v[i][j];

    path[N - 1][M - 1] = 1;
    cout << DFS(0, 0, v, path);

    return 0;
}