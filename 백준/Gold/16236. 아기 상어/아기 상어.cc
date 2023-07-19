#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstring>

#define PII pair<int, int>
#define TIII tuple<int, int, int>

using namespace std;

int N, arr[20][20], SharkSize = 2, EatCount, Time;
bool visited[20][20];

int dirx[4] = { -1, 0, 0, 1 };
int diry[4] = { 0, -1, 1, 0 };

PII Shark;



PII BFS()
{
	PII start = Shark;

	queue<TIII> q;
	vector<TIII> v;

	q.push(TIII(start.first, start.second, 0));

	visited[Shark.first][Shark.second] = true;

	while(!q.empty())
	{
		TIII tmp = q.front();
		q.pop();

		for(int i = 0; i < 4; i++)
		{
			int newx = get<0>(tmp) + dirx[i];
			int newy = get<1>(tmp) + diry[i];

			if (newx < 0 || newx > N - 1 || newy < 0 || newy > N - 1 || visited[newx][newy] == true || arr[newx][newy] > SharkSize)
				continue;

			if (arr[newx][newy] != 0 && arr[newx][newy] < SharkSize)
				v.emplace_back(newx, newy, get<2>(tmp)+1);
			else
			{
				q.push(TIII(newx, newy, get<2>(tmp)+1));
				visited[newx][newy] = true;
			}
		}
	}

	if(!v.empty())
	{
		sort(v.begin(), v.end(), [](TIII a, TIII b)
		{
			if(get<2>(a) == get<2>(b))
			{
				if (get<0>(a) == get<0>(b))
					return get<1>(a) < get<1>(b);
				else
					return get<0>(a) < get<0>(b);
			}
			return get<2>(a) < get<2>(b);
		});

		Time += get<2>(v[0]);
		return PII(get<0>(v[0]), get<1>(v[0]));
	}

	return start;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if(arr[i][j] == 9)
			{
				Shark.first = i;
				Shark.second = j;
			}
		}
	}
	
	PII next = BFS();
	
	while(next != Shark)
	{
		memset(visited, false, sizeof(bool) * 20 * 20);
		EatCount++;
		if(EatCount == SharkSize)
		{
			EatCount = 0;
			SharkSize++;
		}

		arr[Shark.first][Shark.second] = 0;
		arr[next.first][next.second] = 9;

		Shark = next;
		next = BFS();
	}

	cout << Time;

	return 0;
}