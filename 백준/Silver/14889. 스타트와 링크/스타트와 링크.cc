#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int arr[20][20];
bool visited[20];
int ans = 2147483647, N;

int GetScore(vector<int>& v)
{
	int sum = 0;
	for(int i = 0; i < v.size()-1; i++)
	{
		int x = v[i];
		for(int j = i+1; j < v.size(); j++)
		{
			int y = v[j];
			sum += arr[x][y] + arr[y][x];
		}
	}
	return sum;
}

int GetDifference(vector<int>& v)
{
	vector<int> v2;

	for(int i = 0; i < N; i++)
	{
		if (visited[i] == false)
			v2.push_back(i);
	}

	int a = GetScore(v);
	int b = GetScore(v2);

	return abs(a-b);
}

void dfs(int idx, int cnt, vector<int>& v)
{
	if (cnt == N/2)
	{
		ans = min(ans, GetDifference(v));
		return;
	}
	cnt++;
	for(int i = idx+1; i < N; i++)
	{
		v.push_back(i);
		visited[i] = true;
		dfs(i, cnt, v);
		visited[i] = false;
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	vector<int> v;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	for(int i = 0; i < N; i++)
	{
		v.push_back(i);
		visited[i] = true;
		dfs(i, 1, v);
		visited[i] = false;
		v.pop_back();
	}

	cout << ans;
	
	return 0;
}