#include <iostream>
#include <math.h>

using namespace std;

bool paper[100][100];

void changeColor(int x, int y)
{
	for(int i = x; i < x + 10; i++)
	{
		for(int j = y; j < y + 10; j++)
		{
			paper[i][j] = true;
		}
	}
}

int CountColor()
{
	int cnt = 0;
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			if (paper[i][j] == true)
				cnt++;
		}
	}

	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;

		changeColor(x, y);
	}

	cout << CountColor();

	return 0;
}