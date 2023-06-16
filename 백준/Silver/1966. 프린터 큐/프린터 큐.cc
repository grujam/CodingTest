#include <iostream>
#include <queue>

#define PII pair<int, int>

using namespace std;

struct cmp
{
	bool operator ()(PII a, PII b)
	{
		return a.second < b.second;
	}
};

void Test()
{
	int N, M, cnt = 0;
	cin >> N >> M;

	queue<PII> q;
	priority_queue<PII, vector<PII>, cmp> pq;

	for(int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		q.push(PII(i, n));
		pq.push(PII(i, n));
	}

	while(!q.empty())
	{
		PII qfront = q.front();
		PII pqtop = pq.top();

		if(pqtop.second == qfront.second)
		{
			if(qfront.first == M)
			{
				cout << ++cnt << "\n";
				return;
			}
			q.pop();
			pq.pop();
			cnt++;
		}
		else
		{
			q.push(qfront);
			q.pop();
			pq.push(pqtop);
			pq.pop();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		Test();
	}

	return 0;
}