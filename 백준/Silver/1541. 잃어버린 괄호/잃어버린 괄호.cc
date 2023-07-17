#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	int ans, num;
	char c;
	bool check = false;

	cin >> str;
	stringstream ss(str);

	ss >> ans;

	while(ss >> c >> num)
	{
		if(check)
		{
			ans -= num;
			continue;
		}
		switch(c)
		{
		case '+':
			ans += num;
			break;
		case '-':
			check = true;
			ans -= num;
			break;
		}
	}

	cout << ans;

	return 0;
}