#include <iostream>
#include <queue>
#include <algorithm>

#define PII pair<int, int>

using namespace std;

struct cmp
{
	bool operator()(PII a, PII b)
	{
		if (a.first == b.first)
			return a.second > b.second;
		return a.first > b.first;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	priority_queue<PII, vector<PII>, cmp> pq;

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;

		pq.push(PII(a, b));
	}

	int end = 0, cnt = 0;

	while(!pq.empty())
	{
		if(pq.top().first < end)
		{
			pq.pop();
			continue;
		}

		if(pq.top().first == pq.top().second)
		{
			end = pq.top().second;
			pq.pop();
			cnt++;
			continue;
		}

		PII tmp = pq.top();
		pq.pop();

		while(!pq.empty() && pq.top().first < tmp.second)
		{
			if (pq.top().first == pq.top().second)
			{
				tmp = pq.top();
				pq.pop();
				break;
			}
			else if (pq.top().second < tmp.second)
				tmp = pq.top();
			pq.pop();
		}

		cnt++;
		end = tmp.second;
	}

	cout << cnt;

	return 0;
}