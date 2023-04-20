#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int table[101][100001];

int main()
{

	int N, K, w, v;
	
	cin >> N >> K;

	vector<int> W;
	vector<int> V;

	W.push_back(0);
	V.push_back(0);
	for (int i = 0; i < N; i++)
	{
		cin >> w >> v;
		W.push_back(w);
		V.push_back(v);
	}

	for (int j = 0; j < N+1; j++)
	{
		for (int k = 0; k < K+1; k++)
		{
			if (j == 0 || k == 0)
			{
				table[j][k] = 0;
				continue;
			}
			if (W[j] > k)
				table[j][k] = table[j - 1][k];
			else
			{
				table[j][k] = max(V[j] + table[j - 1][k - W[j]], table[j - 1][k]);
			}
		}
	}

	cout << table[N][K];

	return 0;
}