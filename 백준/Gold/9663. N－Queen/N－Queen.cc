#include <iostream>

using namespace std;

int result = 0;

int board[15][15] = {0,};
int arry[15] = {0,};
int dirx[2] = {-1, -1};
int diry[2] = {-1, 1};

bool check(int x, int y, int N)
{
	for(int i = 0; i <2; i++)  
	{
		int tempx = x;
		int tempy = y;
		while(tempx + dirx[i] > -1 && tempx + dirx[i] < N && tempy + diry[i] > -1 && tempy + diry[i] < N)
		{
			tempx += dirx[i];
			tempy += diry[i];
			if (board[tempx][tempy] == 1)
				return true;
		}
	}
	return false;
}

void findQueen(int x, int N)
{
	if (x == N)
	{
		result++;
		return;
	}

	for(int i = 0; i < N; i++)
	{
		if (arry[i] == 1)
			continue;
		if(!check(x,i, N))
		{
			board[x][i] = 1;
			arry[i] = 1;
			findQueen(x+1, N);
			arry[i] = 0;
			board[x][i] = 0;
		}
	}
	return;
}


int main()
{
	int N;

	cin >> N;
	findQueen(0, N);

	cout << result;

	return 0;
}