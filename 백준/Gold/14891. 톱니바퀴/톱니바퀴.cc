#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>

using namespace std;

vector<deque<int>> v(4, deque<int>());

enum
{
	CCW = -1, CW = 1, LFT, RGT
};

void TurnWheel(int num, int dir, int before)
{
	if (num - 1 > -1 && v[num - 1][2] != v[num][6] && before != RGT)
		TurnWheel(num - 1, dir * -1, LFT);
	if (num + 1 < 4 && v[num + 1][6] != v[num][2] && before != LFT)
		TurnWheel(num + 1, dir * -1, RGT);

	if(dir == CCW)
	{
		v[num].push_back(v[num].front());
		v[num].pop_front();
	}
	else
	{
		v[num].push_front(v[num].back());
		v[num].pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(int i = 0; i < 4; i++)
	{
		string s;
		cin >> s;

		for(int j = 0; j < 8; j++)
		{
			v[i].push_back(s[j]-'0');
		}
	}

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int wheel, direction;
		cin >> wheel >> direction;

		TurnWheel(wheel-1, direction, 0);
	}

	int cnt = 0;
	for(int i = 0; i < 4; i++)
	{
		if (v[i][0] == 1)
			cnt += pow(2, i);
	}

	cout << cnt;

	return 0;
}