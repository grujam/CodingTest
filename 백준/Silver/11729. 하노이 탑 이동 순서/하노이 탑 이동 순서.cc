#include <iostream>
#include <math.h>

using namespace std;

void Print(int start, int dest)
{
	cout << start << " " << dest << "\n";
}

void HanoiTower(int N, int start, int by, int dest)
{
	if (N == 0)
		return;

	HanoiTower(N - 1, start, dest, by);
	Print(start, dest);
	HanoiTower(N - 1, by, start, dest);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int num = (int)pow(2, N) - 1;

	cout << num << "\n";

	HanoiTower(N, 1, 2, 3);

	return 0;
}