#include <iostream>
#include <algorithm>
#include <deque>

#define TIII tuple<int, int, int>

int dirx[4] = { 0, -1, 0, 1 };
int diry[4] = { -1, 0, 1, 0 };

using namespace std;

int arr[201][201];

void Infect(int x, int y, deque<TIII>& dq, int& N)
{
	int num = arr[x][y];

	for(int i = 0; i < 4; i++)
	{
		int newx = x + dirx[i];
		int newy = y + diry[i];

		if (newx < 1 || newx > N || newy < 1 || newy > N || arr[newx][newy] != 0)
			continue;

		arr[newx][newy] = num;
		dq.emplace_back(make_tuple(newx, newy, arr[newx][newy]));
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	deque<TIII> dq;

	int N, K, S, X, Y;
	cin >> N >> K;

	for(int i = 1; i < N+1; i++)
	{
		for(int j = 1; j < N+1; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] != 0)
				dq.emplace_back(make_tuple(i, j, arr[i][j]));
		}
	}

	sort(dq.begin(), dq.end(), [](TIII a, TIII b)
	{
		return get<2>(a) < get<2>(b);
	});

	cin >> S >> X >> Y;

	for(int i = 0; i < S; i++)
	{
		int num = dq.size();

		for(int j = 0; j < num; j++)
		{
			Infect(get<0>(dq[0]), get<1>(dq[0]), dq, N);
			dq.pop_front();
		}
	}

	cout << arr[X][Y];

	return 0;
}