#include <iostream>
#include <tuple>
#include <vector>

#define TIII tuple<int, int, int>

using namespace std;

int N, M, ans = 64;

vector<TIII> v;

enum
{
	LEFT, UP, RIGHT, DOWN
};

int BlindSpot(vector<vector<int>> office)
{
    int cnt = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
            if (office[i][j] == 0)
                cnt++;
		}
	}

    return cnt;
}

void Line(int x, int y, int dir, vector<vector<int>>& office)
{

	switch(dir)
	{
	case LEFT:
		y--;
		while(x < N && y < M && x > -1 && y > -1 && office[x][y] != 6)
		{
			if (office[x][y] == 0)
				office[x][y] = 7;

			y--;
		}
		break;

	case UP:
		x--;
		while (x < N && y < M && x > -1 && y > -1 && office[x][y] != 6)
		{
			if (office[x][y] == 0)
				office[x][y] = 7;

			x--;
		}
		break;

	case RIGHT:
		y++;
		while (x < N && y < M && x > -1 && y > -1 && office[x][y] != 6)
		{
			if (office[x][y] == 0)
				office[x][y] = 7;

			y++;
		}
		break;

	case DOWN:
		x++;
		while (x < N && y < M && x > -1 && y > -1 && office[x][y] != 6)
		{
			if (office[x][y] == 0)
				office[x][y] = 7;

			x++;
		}
		break;
	}
}

vector<vector<int>> View(TIII camera, vector<vector<int>> office, int i)
{
    int x = get<0>(camera);
    int y = get<1>(camera);
	switch(get<2>(camera))
	{
	case 1:
		Line(x, y, i, office);
		break;
	case 2:
		Line(x, y, i, office);
		Line(x, y, (i + 2) % 4, office);
		break;
	case 3:
		Line(x, y, i, office);
		Line(x, y, (i + 1) % 4, office);
		break;
	case 4:
		Line(x, y, i, office);
		Line(x, y, (i + 1) % 4, office);
		Line(x, y, (i + 2) % 4, office);
		break;
	case 5:
		Line(x, y, 0, office);
		Line(x, y, 1, office);
		Line(x, y, 2, office);
		Line(x, y, 3, office);
		break;
	}
	return office;
}

void Check(int cnt, vector<vector<int>> office)
{
	if(cnt == v.size())
	{
        ans = min(ans, BlindSpot(office));
        return;
	}

    for(int i = 0; i < 4; i++)
    {
        vector<vector<int>> off = View(v[cnt], office, i);
        Check(cnt+1, off);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> office(N, vector<int>(M, 0));
    for(int i = 0; i < N; i++)
    {
	    for(int j = 0; j < M; j++)
	    {
            cin >> office[i][j];
            if(office[i][j] != 0 && office[i][j] != 6)
            {
                v.emplace_back(i, j, office[i][j]);
            }
	    }
    }

	Check(0, office);

	cout << ans;
}