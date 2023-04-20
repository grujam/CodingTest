#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	int ari;

	cin >> s >> ari;

	int len = s.size();
	int ans = 0;

	for(int i = 0; i < len/2; i++)
	{
		char tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
	}

	for(int i = 0; i < len; i++)
	{
		int tmp;

		if (int(s[i]) - 48 > 10)
			tmp = s[i] - 55;
		else
			tmp = s[i] - 48;

		ans += (tmp * pow(ari, i));
	}

	cout << ans;

	return 0;
}