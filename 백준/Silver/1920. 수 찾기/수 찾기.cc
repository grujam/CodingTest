#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	set<long long> s;

	for(int i = 0; i < N; i++)
	{
		long long n;
		cin >> n;
		s.insert(n);
	}

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		long long n;
		cin >> n;
		if (s.find(n) != s.end())
			cout << "1\n";
		else
			cout << "0\n";

	}

	return 0;
}