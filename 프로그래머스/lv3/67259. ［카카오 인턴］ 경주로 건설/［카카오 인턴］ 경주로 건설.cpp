#include <string>
#include <vector>

#define INF 999999

using namespace std;

int cost[26][26];
int visited[26][26];
int N;

int dirx[4] = {0, -1, 0, 1};
int diry[4] = { -1, 0, 1, 0};

void dfs(int x, int y, int befx, int befy)
{
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dirx[i];
        int nexty = y + diry[i];
        if (nextx < 0 || nextx > N - 1 || nexty < 0 || nexty > N - 1)
            continue;

        if (cost[nextx][nexty] == -1 || visited[nextx][nexty] == 1)
            continue;

        if(nextx == N-1 && nexty == N-1)
        {
            if(befx != nextx && befy != nexty)
                cost[nextx][nexty] = min(cost[nextx][nexty], cost[x][y] + 600);
            else
                cost[nextx][nexty] = min(cost[nextx][nexty], cost[x][y] + 100);
            
            return;
        }
        
        if (befx != nextx && befy != nexty)
        {
            if(cost[nextx][nexty] >= cost[x][y] + 200)
            {
                cost[nextx][nexty] = cost[x][y] + 600;
                visited[x][y] = 1;
                dfs(nextx, nexty, x, y);
                visited[x][y] = 0;
            }
		}
		else
		{
            if(cost[nextx][nexty] >= cost[x][y] - 300)
            {
                cost[nextx][nexty] = cost[x][y] + 100;
                visited[x][y] = 1;
                dfs(nextx, nexty, x, y);
                visited[x][y] = 0;
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    N = board.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 && j == 0)
                cost[i][j] = 0;
            else if (board[i][j] == 1)
                cost[i][j] = -1;
            else
                cost[i][j] = INF;
        }
    }

    dfs(0, 0, 0, 0);

    return cost[N - 1][N - 1];
}