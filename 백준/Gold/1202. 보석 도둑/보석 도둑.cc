#include <iostream>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

#define PII pair<int, int>

struct cmp
{
	bool operator()(PII a, PII b)
	{
		return a.second < b.second;
	}
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, K;
	cin >> N >> K;

	priority_queue<PII, vector<PII>, cmp> Jewels;
	multiset<int> Bags;

	for(int i = 0; i < N; i++)
	{
		int weight, price;
		cin >> weight >> price;

		Jewels.emplace(weight, price);
	}

	for(int i = 0; i < K; i++)
	{
		int S;
		cin >> S;

		Bags.insert(S);
	}

	long long total = 0;

	while(!Jewels.empty() && !Bags.empty())
	{
		int weight = Jewels.top().first;
		int price = Jewels.top().second;
		Jewels.pop();

		auto iter = Bags.lower_bound(weight);

		if(iter != Bags.end())
		{
			total += (long long)price;
			Bags.erase(iter);
		}
	}

	cout << total;

	return 0;
}