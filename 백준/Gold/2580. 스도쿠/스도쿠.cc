#include <iostream>
#include <deque>

#define PII pair<int, int>

using namespace std;

int sudoku[9][9];

bool Check(int x, int y, int num)
{
	for(int i = 0; i < 9; i++)
	{
		if (sudoku[x][i] == num || sudoku[i][y] == num)
			return false;
	}

	int a = (x / 3) * 3;
	int b = (y / 3) * 3;

	for(int i = a; i < a + 3; i++)
	{
		for(int j = b; j < b + 3; j++)
		{
			if (sudoku[i][j] == num)
				return false;
		}
	}

	return true;
}

void Print()
{
	for(int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudoku[i][j] << ' ';
		}
		cout << '\n';
	}
}

void dfs(deque<PII>& dq)
{
	if(dq.empty())
	{
		Print();
		exit(0);
	}

	PII cur = dq.front();
	dq.pop_front();

	for(int i = 1; i < 10; i++)
	{
		if(Check(cur.first, cur.second, i))
		{
			sudoku[cur.first][cur.second] = i;
			dfs(dq);
			sudoku[cur.first][cur.second] = 0;
		}
	}

	dq.emplace_front(cur);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int cnt = 0;

	deque<pair<int, int>> dq;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> sudoku[i][j];
			if(sudoku[i][j] == 0)
			{
				dq.emplace_back(i, j);
				cnt++;
			}
		}
	}

	dfs(dq);

	return 0;
}