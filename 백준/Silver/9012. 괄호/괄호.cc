#include <iostream>
#include <string>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	string s;

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> s;
		int cnt = 0;

		for(int j = 0; j < s.length(); j++)
		{
			if (s[j] == ')')
				cnt--;
			else if (s[j] == '(')
				cnt++;

			if(cnt < 0)
			{
				cout << "NO\n";
				break;
			}
		}
		if (cnt == 0)
			cout << "YES\n";
		else if (cnt > 0)
			cout << "NO\n";
	}


	return 0;
}