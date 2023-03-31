#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, crane, M, box;

	vector<int> cranes;
	vector<int> boxes;

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> crane;
		cranes.push_back(crane);
	}
	
	cin >> M;

	for(int i = 0; i < M; i++)
	{
		cin >> box;
		boxes.push_back(box);
	}

	sort(cranes.begin(), cranes.end(), greater<>());
	sort(boxes.begin(), boxes.end(), greater<>());

	if(cranes[0] < boxes[0])
	{
		cout << -1;
		return 0;
	}

	const int cranesNum = cranes.size();

	int cnt = 0;

	while(!boxes.empty())
	{
		for(int i = 0; i < cranesNum; i++)
		{
			for(int j = 0; j < boxes.size(); j++)
			{
				if(cranes[i] >= boxes[j])
				{
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
		}
		cnt++;
	}

	cout << cnt;

	return 0;
}