#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<int> v;
	map<int, int> m;

	int N, num;
	double total = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v.emplace_back(num);
		total += num;
		m[num]++;
	}

	vector<pair<int, int>> vm(m.begin(), m.end());

	sort(v.begin(), v.end());
	sort(vm.begin(), vm.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second > b.second;
		});

	total = trunc((total / N) * 10) / 10;
	int avg = round(total);

	int median = v[N / 2];

	int mode;

	if (vm.size() > 2 && vm[0].second == vm[1].second)
		mode = vm[1].first;
	else
		mode = vm[0].first;

	int range = v[N - 1] - v[0];


	cout << avg << "\n"
		<< median << "\n"
		<< mode << "\n"
		<< range;

	return 0;
}