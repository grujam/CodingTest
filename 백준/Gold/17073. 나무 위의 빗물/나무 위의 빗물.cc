#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
	int N, U, V;
	double W;
	double count = 0.0;

	cin >> N >> W;
	vector<int> v(N + 1, 0);
	for (int i = 0; i < N-1; i++)
	{
		cin >> U >> V;
		v[U]++;
		v[V]++;

	}

	for (int j = 2; j < v.size(); j++)
	{
		if (v[j] == 1)
			count++;
	}
	cout.precision(10);
	cout << fixed << W/count;

	return 0;
}