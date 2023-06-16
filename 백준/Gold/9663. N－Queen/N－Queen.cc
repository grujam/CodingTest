#include <iostream>

using namespace std;

bool visited[16][16];
bool row[16];

int N, ans;

int dirx[2] = { -1, -1 };
int diry[2] = { -1, 1 };

bool CheckDiagonalWays(int x, int y)
{
	int lftx = x + dirx[0];
	int lfty = y + diry[0];

	int rgtx = x + dirx[1];
	int rgty = y + diry[1];
	
	while(lftx > -1 && lftx < N && lfty > -1 && lfty < N)
	{
		if (visited[lftx][lfty] == true)
			return false;

		lftx += dirx[0];
		lfty += diry[0];
	}

	while (rgtx > -1 && rgtx < N && rgty > -1 && rgty < N)
	{
		if (visited[rgtx][rgty] == true)
			return false;

		rgtx += dirx[1];
		rgty += diry[1];
	}

	return true;
}

void dfs(int x, int y)
{
	if(x == N-1)
	{
		ans++;
		return;
	}

	x++;

	for(int i = 0; i < N; i++)
	{
		if (row[i] == true)
			continue;

		if(CheckDiagonalWays(x, i))
		{
			row[i] = true;
			visited[x][i] = true;
			dfs(x, i);
			visited[x][i] = false;
			row[i] = false;
		}
	}
}

void NQueen()
{
	for(int i = 0; i < N; i++)
	{
		row[i] = true;
		visited[0][i] = true;
		dfs(0, i);
		visited[0][i] = false;
		row[i] = false;
	}

	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	NQueen();

	return 0;
}