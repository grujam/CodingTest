#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int ans, N, M;

int arr[500][500];

void OnebyFour(const int& x, const int& y)
{
	if (y + 3 >= M)
		return;

	int total = 0;

	for (int j = y; j < y + 4; j++)
		total += arr[x][j];

	// 가로 테트로미노
	ans = max(ans, total);
}

void TwobyThree(const int& x, const int& y)
{
	if (x + 1 >= N || y + 2 >= M)
		return;

	int total = 0;

	for(int i = x; i < x+2; i++)
	{
		for(int j = y; j < y+3; j++)
		{
			total += arr[i][j];
		}
	}

	//네모 테트로미노
	ans = max(max(ans, total - arr[x][y+2] - arr[x+1][y+2]), total - arr[x][y] - arr[x+1][y]);

	//L or J 테트로미노
	ans = max(max(ans, total - arr[x + 1][y + 1] - arr[x + 1][y + 2]), total - arr[x + 1][y] - arr[x + 1][y + 1]);
	ans = max(max(ans, total - arr[x][y] - arr[x][y + 1]), total - arr[x][y + 1] - arr[x][y + 2]);

	//Z or S 테트로미노
	ans = max(max(ans, total - arr[x][y] - arr[x + 1][y + 2]), total - arr[x + 1][y] - arr[x][y + 2]);

	//T 테트로미노
	ans = max(max(ans, total - arr[x][y] - arr[x][y + 2]), total - arr[x + 1][y] - arr[x + 1][y + 2]);
}

void ThreebyTwo(const int& x, const int& y)
{
	if (x + 2 >= N || y + 1 >= M)
		return;

	int total = 0;

	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 2; j++)
		{
			total += arr[i][j];
		}
	}

	//L or J 테트로미노
	ans = max(max(ans, total - arr[x][y] - arr[x + 1][y]), total - arr[x][y + 1] - arr[x + 1][y + 1]);
	ans = max(max(ans, total - arr[x + 1][y] - arr[x + 2][y]), total - arr[x + 1][y + 1] - arr[x + 2][y + 1]);

	//Z or S 테트로미노
	ans = max(max(ans, total - arr[x][y] - arr[x + 2][y + 1]), total - arr[x][y + 1] - arr[x + 2][y]);

	//T 테트로미노
	ans = max(max(ans, total - arr[x][y + 1] - arr[x + 2][y + 1]), total - arr[x][y] - arr[x + 2][y]);
}

void FourbyOne(const int& x, const int& y)
{
	if (x + 3 >= N)
		return;

	int total = 0;

	for (int i = x; i < x + 4; i++)
		total += arr[i][y];

	ans = max(ans, total);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			cin >> arr[i][j];

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			OnebyFour(i, j);
			TwobyThree(i, j);
			ThreebyTwo(i, j);
			FourbyOne(i, j);
		}
	}
	
	cout << ans;

	return 0;
}