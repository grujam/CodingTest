#include <iostream>
#include <vector>

#define PII pair<int, int>
#define INF 9999999

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> v(n, vector<int>(n, INF));

	for (int i = 0; i < n; i++)
		v[i][i] = 0;

	for(int i = 0; i < m; i++)
	{
		int start, dest, weight;
		cin >> start >> dest >> weight;

		v[start - 1][dest - 1] = min(weight, v[start - 1][dest - 1]);
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				v[j][k] = min(v[j][k], v[j][i] + v[i][k]);
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (v[i][j] == INF)
				cout << "0 ";
			else
				cout << v[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}