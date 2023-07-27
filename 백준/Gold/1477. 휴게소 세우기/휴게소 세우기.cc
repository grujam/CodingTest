#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L;

int Check(int n, vector<int>& v)
{
	int cnt = 0;

	int before = 0, end = L;

	for(int i = 0; i < v.size(); i++)
	{
		int dist = v[i] - before;

		if (dist % n == 0)
			cnt += (dist / n) - 1;
		else
			cnt += (dist / n);

		before = v[i];
	}

	int dist = end - before;

	if (dist % n == 0)
		cnt += (dist / n) - 1;
	else
		cnt += (dist / n);

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M >> L;

	vector<int> v(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	int low = 0, high = L-1;

	while(low + 1 < high)
	{
		int mid = (low + high) / 2;

		if (Check(mid, v) > M)
			low = mid;
		else
			high = mid;
	}

	cout << high;

	return 0;
}