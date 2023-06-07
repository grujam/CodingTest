#include <iostream>
#include <map>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	map<string, string> m;
	priority_queue<string> pq;

	for(int i = 0; i < N; i++)
	{
		string str, absence;

		cin >> str >> absence;

		m[str] = absence;
	}

	for(auto& resource : m)
	{
		if (resource.second == "enter")
			pq.push(resource.first);
	}

	while(!pq.empty())
	{
		cout << pq.top() << "\n";
		pq.pop();
	}

	return 0;
}