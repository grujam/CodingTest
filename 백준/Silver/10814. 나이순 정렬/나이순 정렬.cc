#include <iostream>
#include <vector>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;

	vector<vector<string>> v(201);

	for(int i = 0; i < N; i++)
	{
		int num;
		string name;

		cin >> num >> name;

		v[num].emplace_back(name);
	}

	for(int i = 0; i < 201; i++)
	{
		for(int j = 0; j < v[i].size(); j++)
		{
			cout << i << " " << v[i][j] << "\n";
		}
	}

	return 0;
}