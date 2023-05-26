#include <iostream>

using namespace std;

void Print(int n, string s)
{
	string str;
	for(int i = 0; i < s.length(); i++)
	{
		for(int j = 0; j < n; j++)
		{
			str += s[i];
		}
	}

	cout << str << "\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int n;
		string s;
		cin >> n >> s;

		Print(n, s);
	}

	return 0;
}