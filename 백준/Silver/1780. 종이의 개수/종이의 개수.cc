#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[3];

bool Check(int x, int y, int N, vector<vector<int>>& v)
{
	int tmp = v[x][y];

	for(int i = x; i < x+N; i++)
	{
		for(int j = y; j < y+N; j++)
		{
			if (v[i][j] != tmp)
				return false;
		}
	}

	arr[tmp+1]++;

	return true;
}

void Thirds(int x, int y, int N, vector<vector<int>>& v)
{
	int a, b;

	if (Check(x, y, N, v) == true)
		return;

	N /= 3;

	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			a = i * N + x;
			b = j * N + y;

			Thirds(a, b, N, v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N, 0));

	for(int i = 0; i < N; i++)
		for(int j = 0; j < N; j++)
			cin >> v[i][j];

	Thirds(0, 0, N, v);

	cout << arr[0] << "\n" << arr[1] << "\n" << arr[2];

	return 0;
}