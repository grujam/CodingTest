#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;

bool CheckQuad(int x, int y, vector<vector<int>>& v, int N)
{
	int num = v[x][y];

	for(int i = x; i < x+N; i++)
	{
		for(int j = y; j < y+N; j++)
		{
			if (v[i][j] != num)
				return false;
		}
	}

	s += to_string(num);
	return true;
}

void Quad(int x, int y, vector<vector<int>>& v, int N)
{
	if(CheckQuad(x,y,v,N) == false)
	{
		s += "(";

		N /= 2;
		Quad(x, y, v, N);
		Quad(x, y+N, v, N);
		Quad(x+N, y, v, N);
		Quad(x+N, y+N, v, N);

		s += ")";
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N, 0));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			char c;
			cin >> c;

			v[i][j] = c - '0';
		}
	}

	Quad(0, 0, v, N);

	cout << s;

	return 0;
}