#include <iostream>

using namespace std;

int parent[1000001];

int Find(int v)
{
	if (parent[v] == v) return v;
	
	return parent[v] = Find(parent[v]);
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

	int n, m;

	cin >> n >> m;

	for(int i = 0; i < n+1; i++)
	{
		parent[i] = i;
	}

	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> c >> a >> b;

		if (c == 0)
			Union(a, b);
		else
		{
			if (Find(a) == Find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}