#include <iostream>
#include <queue>

#define PII pair<int, int>

using namespace std;

struct cmp
{
	bool operator ()(PII a, PII b)
	{
		if (a.first == b.first)
			return a.second > b.second;

		return a.first > b.first;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	priority_queue<PII, vector<PII>, cmp> pq;

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		PII tmp;

		cin >> tmp.first >> tmp.second;

		pq.push(tmp);
	}

	for(int i = 0; i < N; i++)
	{
		PII tmp = pq.top();
		pq.pop();

		cout << tmp.first << " " << tmp.second << "\n";
	}


	return 0;
}