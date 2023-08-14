#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int N, M, ans;

vector<PII> v;

int arr[8][8];

int dirx[4] = { 0, -1, 0, 1 };
int diry[4] = { -1, 0, 1, 0 };

void Count()
{
    int total = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
            if (arr[i][j] == 0)
                total++;

            if (arr[i][j] == 3)
                arr[i][j] = 0;
		}
	}

    ans = max(ans, total);
}

void Virus(int x, int y)
{
	for(int i = 0; i < 4; i++)
	{
        int newx = x + dirx[i];
        int newy = y + diry[i];

        if (newx < 0 || newx > N - 1 || newy < 0 || newy > M - 1)
            continue;

        if(arr[newx][newy] == 0)
        {
            arr[newx][newy] = 3;
            Virus(newx, newy);
        }
	}
}

void BuildWall(int x, int y, int cnt)
{
    if (cnt == 3)
    {
        for (PII& pii : v)
        {
            Virus(pii.first, pii.second);
        }
        Count();
        return;
    }

    cnt++;

    for(int i = x; i < N; i++)
    {
	    for(int j = y+1; j < M; j++)
	    {
		    if(arr[i][j] == 0)
		    {
                arr[i][j] = 1;
                BuildWall(i, j, cnt);
                arr[i][j] = 0;
		    }
	    }
        y = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> N >> M;

    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                v.emplace_back(i, j);
        }
    }


    for(int i = 0; i < N; i++)
    {
	    for(int j = 0; j < M; j++)
	    {
            if (arr[i][j] == 0)
            {
                arr[i][j] = 1;
                BuildWall(i, j, 1);
                arr[i][j] = 0;
            }
	    }
    }

    cout << ans;

    return 0;
}