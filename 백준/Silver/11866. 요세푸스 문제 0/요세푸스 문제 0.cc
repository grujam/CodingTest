#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	int N, K;
	do {
		cin >> N >> K;
	} while (N > 5000 && N < 1 && K > 5000 && K < 1);

	for (int i = 0; i < N; i++)
	{
		q.push(i+1);
	}

	cout << "<";

	while (!q.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}
		if (q.size() == 1) {
			cout << q.front() << ">";
			q.pop();
		}
		else {
			cout << q.front() << ", ";
			q.pop();
		}
		
	}


	return 0;
}