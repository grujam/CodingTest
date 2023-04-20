#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int y_size;
int x_size;

void dfs(vector<vector<int>>& field, vector<vector<int>> &visited, int y, int x)
{
    visited[y][x] = 1;
    // 위아래 확인
    if (y == 0)
    {
        // 아래만
        if (visited[y + 1][x] == 0 && field[y + 1][x] == 1) {
            dfs(field, visited, y + 1, x);
        }
    }
    else if (y == y_size - 1)
    {
        // 위만
        if (visited[y - 1][x] == 0 && field[y - 1][x] == 1) {
            dfs(field, visited, y - 1, x);
        }
    }
    else
    {
        // 양방향
        if (visited[y + 1][x] == 0 && field[y + 1][x] == 1) {
            dfs(field, visited, y + 1, x);
        }
        if (visited[y - 1][x] == 0 && field[y - 1][x] == 1) {
            dfs(field, visited, y - 1, x);
        }
    }

    // 좌우 확인
    if (x == 0)
    {
        // 오른쪽만
        if (visited[y][x + 1] == 0 && field[y][x + 1] == 1) {
            dfs(field, visited, y, x + 1);
        }
    }
    else if (x == x_size - 1)
    {
        // 왼쪽만
        if (visited[y][x - 1] == 0 && field[y][x - 1] == 1) {
            dfs(field, visited, y, x - 1);
        }
    }
    else
    {
        // 양방향
        if (visited[y][x + 1] == 0 && field[y][x + 1] == 1) {
            dfs(field, visited, y, x + 1);
        }
        if (visited[y][x - 1] == 0 && field[y][x - 1] == 1) {
            dfs(field, visited, y, x - 1);
        }
    }

}


int main()
{
    int T, M, N, K, X, Y;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int count = 0;
        cin >> M >> N >> K;
        vector<vector<int>> field(N, vector<int>(M, 0));
        vector<vector<int>> visited(N, vector<int>(M, 0));

        y_size = N;
        x_size = M;

        for (int k = 0; k < K; k++)
        {
            cin >> X >> Y;

            field[Y][X] = 1;
        }

        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                if (field[y][x] == 1 && visited[y][x] == 0)
                {
                    count++;
                    dfs(field, visited, y, x);
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}