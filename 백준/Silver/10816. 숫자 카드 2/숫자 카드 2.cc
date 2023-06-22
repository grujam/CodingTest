#include <iostream>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	map<int, int> m;

	for(int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		m[num]++;
	}

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		cout << m[num] << " ";
	}

	return 0;
}