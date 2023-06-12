#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void Push(stack<int>& s, queue<char>& q, int& current, int n)
{
	while(s.top() != n)
	{
		s.push(current++);
		q.push('+');
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, current = 1;
	cin >> N;

	stack<int> s;
	queue<char> q;
	s.push(0);

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		if (s.top() > num)
		{
			cout << "NO";
			return 0;
		}
		else if (s.top() == num)
		{
			s.pop();
			q.push('-');
		}
		else
		{
			Push(s, q, current, num);
			s.pop();
			q.push('-');
		}
	}


	while (!q.empty())
	{
		cout << q.front() << "\n";
		q.pop();
	}

	return 0;
}