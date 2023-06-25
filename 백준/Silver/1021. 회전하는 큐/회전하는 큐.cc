#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int FindAndAdjust(int n, int& size, deque<int>& dq)
{
	auto iter = find(dq.begin(), dq.end(), n);
	int idx = iter - dq.begin();

	int cnt = 0;

	if(idx > size / 2)
	{
		while(dq.front() != n)
		{
			dq.push_front(dq.back());
			dq.pop_back();
			cnt++;
		}

		dq.pop_front();
		size--;
		return cnt;
	}
	else
	{
		while (dq.front() != n)
		{
			dq.push_back(dq.front());
			dq.pop_front();
			cnt++;
		}

		dq.pop_front();
		size--;
		return cnt;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;

	deque<int> dq;

	for(int i = 0; i < N; i++)
	{
		dq.emplace_back(i+1);
	}

	int size = N, sum = 0;

	for(int i = 0; i < M; i++)
	{
		int num;
		cin >> num;

		sum += FindAndAdjust(num, size, dq);
	}

	cout << sum;

	return 0;
}