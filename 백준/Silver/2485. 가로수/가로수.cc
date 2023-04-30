#include <iostream>
#include <numeric>

using namespace std;

int dist[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, tree1, tree2;
	cin >> N;

	cin >> tree1;
	cin >> tree2;
	dist[0] = tree2 - tree1;
	tree1 = tree2;
	int divi = dist[0];

	for(int i = 1; i < N-1; i++)
	{
		cin >> tree2;
		dist[i] = tree2 - tree1;
		tree1 = tree2;

		divi = gcd(divi, dist[i]);
	}

	int cnt = 0;

	for(int i = 0; i < N-1; i++)
	{
		cnt += (dist[i] / divi) - 1;
	}

	cout << cnt;

	return 0;
}