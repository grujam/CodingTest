#include <iostream>

using namespace std;

int parent[201];

int Find(int n)
{
	if (parent[n] == n) return n;

	return parent[n] = Find(parent[n]);
}

bool IsSet(int a, int b)
{
	return Find(a) == Find(b);
}

void Union(int a, int b)
{
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb)
		return;

	parent[pb] = pa;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for(int i = 1; i < N+1; i++)
		parent[i] = i;

	for(int i = 1; i < N+1; i++)
	{
		for(int j = 1; j < N+1; j++)
		{
			int num;
			cin >> num;

			if (num == 1)
				Union(i, j);
		}
	}

	int a, b;

	cin >> a;
	for(int i = 0; i < M-1; i++)
	{
		cin >> b;
		if(IsSet(a,b) == false)
		{
			cout << "NO";
			return 0;
		}
		a = b;
	}
	cout << "YES";
	return 0;
}