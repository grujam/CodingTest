#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	string s;

	map<string, int> m;

	for(int i = 0; i < N; i++)
	{
		cin >> s;
		if (s.length() < M)
			continue;

		m[s]++;
	}

	vector<pair<string, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), [&](pair<string, int> a, pair<string, int> b)
	{
		if(a.second == b.second)
		{
			if (a.first.length() == b.first.length())
				return a.first < b.first;
			return a.first.length() > b.first.length();
		}
		return a.second > b.second;
	});

	for(pair<string, int> psi : v)
	{
		cout << psi.first << "\n";
	}

	return 0;
}