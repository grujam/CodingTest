#include <iostream>

using namespace std;

long long N;

long long price[100000];
long long dist[100000];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	long long total = 0;

	cin >> N;

	for(int i = 1; i < N; i++)
		cin >> dist[i];

	for (int i = 0; i < N; i++)
		cin >> price[i];

	long long curPrice = price[0];

	for(int i = 1; i < N; i++)
	{
		total += curPrice * dist[i];

		curPrice = min(curPrice, price[i]);
	}

	cout << total;

	return 0;
}