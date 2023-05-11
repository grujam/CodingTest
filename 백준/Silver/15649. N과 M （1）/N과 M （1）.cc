#include <iostream>
#include <queue>

using namespace std;

int N, M;

int arr[9];
bool visited[9];
vector<int> v;

void dfs(int idx, int cnt)
{
	if (++cnt == M)
	{
		for(int ele : v)
		{
			cout << ele << " ";
		}
		cout << "\n";
		return;
	}

	for(int i = 1; i < N + 1;i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			v.push_back(arr[i]);
			dfs(i, cnt);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	cin >> N >> M;

	for(int i = 1; i < N+1; i++)
	{
		arr[i] = i;
	}

	for(int i = 1; i < N+1; i++)
	{
		visited[i] = true;
		v.push_back(arr[i]);
		dfs(i, 0);
		v.pop_back();
		visited[i] = false;
	}


	return 0;
}