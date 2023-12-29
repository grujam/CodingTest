#include <iostream>
#include <vector>

#define INF 1000000000

using namespace std;

int dirx[5] = { 0, 0, -1, 0, 1 };
int diry[5] = { 0, -1, 0, 1, 0 };

vector<vector<bool>> bulbs(10, vector<bool>(10, false));
vector<vector<bool>> temp(10, vector<bool>(10, false));;


void Switch(int x, int y)
{
    for(int i = 0; i < 5; i++)
    {
        int newx = x + dirx[i];
        int newy = y + diry[i];

        if (newx < 0 || newy < 0 || newx >= 10 || newy >= 10)
            continue;

        temp[newx][newy] = !temp[newx][newy];
    }
}

int Find(int num)
{
    int cnt = 0;

	for(int i = 0; i < 10 ;i++)
	{
        if (num & 1)
        {
            Switch(0, i);
            cnt++;
        }
        num = num >> 1;
	}

    for(int i = 1; i < 10; i++)
    {
	    for(int j = 0; j < 10; j++)
	    {
            if (temp[i - 1][j] == true)
            {
                Switch(i, j);
                cnt++;
            }
	    }
    }

    for(int i = 0; i < 10; i++)
    {
	    for(int j = 0; j < 10; j++)
	    {
            if (temp[i][j] == true)
                return INF;
	    }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int ans = INF;

    for(int i = 0; i < 10; i++)
    {
	    for(int j = 0; j < 10; j++)
	    {
            char c;
            cin >> c;
            if (c == 'O')
                bulbs[i][j] = true;
	    }
    }

    for (int i = 0; i <= ((1 << 10) - 1); i++)
	{
        temp = bulbs;
        ans = min(ans, Find(i));
	}

    cout << ((ans == INF) ? -1 : ans);

    return 0;
}
