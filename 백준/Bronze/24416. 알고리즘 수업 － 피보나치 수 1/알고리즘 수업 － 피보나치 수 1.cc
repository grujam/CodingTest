#include <iostream>
#include <vector>

using namespace std;

int cnt = 0;

int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		cnt++;
		return 1;
	}

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	fibonacci(N);

	cout << cnt << " " << N-2;


	return 0;
}