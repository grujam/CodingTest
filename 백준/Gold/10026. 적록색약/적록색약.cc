#include <iostream>
#include <cstring>

using namespace std;

char arr[101][101];
bool visited[101][101];

int dirx[4] = { 0,-1,0,1 };
int diry[4] = { -1,0,1,0 };

void BFS(int x, int y, const int& N)
{
    char cur = arr[x][y];

    for(int i = 0; i < 4; i++)
    {
        int newx = x + dirx[i];
        int newy = y + diry[i];

        if (newx > N - 1 || newx < 0 || newy > N - 1 || newy < 0)
            continue;

        if(arr[newx][newy] == cur && visited[newx][newy] == false)
        {
            visited[newx][newy] = true;
            BFS(newx, newy, N);
        }
    }
}

void BFS2(int x, int y, const int& N)
{
    char cur = arr[x][y];

    for (int i = 0; i < 4; i++)
    {
        int newx = x + dirx[i];
        int newy = y + diry[i];

        if (newx > N - 1 || newx < 0 || newy > N - 1 || newy < 0)
            continue;

        if(cur == 'R' ||cur == 'G')
        {
            if (arr[newx][newy] == 'R' || arr[newx][newy] == 'G' )
            {
                if(visited[newx][newy] == false)
                {
                    visited[newx][newy] = true;
                    BFS2(newx, newy, N);
                }
            }
        }
        else if (arr[newx][newy] == cur && visited[newx][newy] == false)
        {
            visited[newx][newy] = true;
            BFS2(newx, newy, N);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> arr[i][j];

    int normal = 0;
    for(int i = 0; i < N; i++)
    {
	    for(int j = 0; j < N; j++)
	    {
            if (visited[i][j] == false)
            {
                visited[i][j] = true;
                BFS(i, j, N);
                normal++;
            }
	    }
    }

    memset(visited, false, sizeof(visited));

    int cblind = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visited[i][j] == false)
            {
                visited[i][j] = true;
                BFS2(i, j, N);
                cblind++;
            }
        }
    }

    cout << normal << " " << cblind;
    return 0;
}