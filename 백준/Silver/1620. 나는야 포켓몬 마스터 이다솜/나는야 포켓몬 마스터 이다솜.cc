#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	map<string, int> pokemon_name;
	vector<string> pokemon_index;

	cin >> N >> M;



	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;

		pokemon_name.insert({ s, i+1 });
		pokemon_index.push_back(s);
	}

	for(int i = 0; i < M; i++)
	{
		string s;
		cin >> s;

		if(s[0] < 65)
		{
			cout << pokemon_index[stoi(s) - 1] << "\n";
		}
		else
		{
			cout << pokemon_name[s] << "\n";
		}

	}
	

	return 0;
}