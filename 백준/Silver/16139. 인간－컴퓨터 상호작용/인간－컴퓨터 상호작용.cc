#include <iostream>

using namespace std;

int arr[26][200001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	cin >> s;

	arr[s[0] - 'a'][0]++;

	for (int j = 1; j < s.length(); j++)
	{
		arr[s[j] - 'a'][j]++;
		for(int i = 0; i < 26; i++)
		{
			arr[i][j] += arr[i][j-1];
		}
	}

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		char c;
		int l, r;


		cin >> c >> l >> r;

		if (l == 0)
			cout << arr[c - 'a'][r] << "\n";
		else
			cout << arr[c - 'a'][r] - arr[c - 'a'][l - 1] << "\n";
	}

	return 0;
}