#include <iostream>
#include <vector>
#include <algorithm>

long long MOD = 1000000007;

using namespace std;

long long binarypow(long long base, long long exp)
{
	long long ret = 1;

	while (exp > 0)
	{
		if (exp & 1)
			ret = (ret * base) % MOD;

		base = (base*base) % MOD;
		exp = exp >> 1;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<long long> v;

	int N;
	cin >> N;

	long long sum = 0;

	for (int i = 0; i < N; i++)
	{
		long long num;
		cin >> num;
		v.emplace_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++)
	{
		long long maxcnt = binarypow(2, i);
		long long mincnt = binarypow(2, N - i - 1);

		sum = (sum + (maxcnt * v[i] % MOD - mincnt * v[i] % MOD + MOD) % MOD) % MOD;

	}

	cout << sum;

	return 0;
}