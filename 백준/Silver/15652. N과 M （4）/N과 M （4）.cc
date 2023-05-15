#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void PrintVector(vector<int>& v)
{
	for (int a : v)
	{
		cout << a << " ";
	}
	cout << "\n";
}

void dfs(int idx, int cnt)
{
	if (++cnt == M)
	{
		PrintVector(v);
		return;
	}

	for (int i = 1; i < N + 1; i++)
	{
		if (i < idx)
			continue;
		v.push_back(i);
		dfs(i, cnt);
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i < N + 1; i++)
	{
		v.push_back(i);
		dfs(i, 0);
		v.pop_back();
	}


	return 0;
}