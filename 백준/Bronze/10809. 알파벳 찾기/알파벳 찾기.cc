#include <iostream>

using namespace std;

int arr[26];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 26; i++)
		arr[i] = -1;

	string s;
	cin >> s;

	for(int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if (arr[c - 97] == -1)
			arr[c - 97] = i;
	}

	for (int i = 0; i < 26; i++)
		cout << arr[i] << ' ';

	return 0;
}