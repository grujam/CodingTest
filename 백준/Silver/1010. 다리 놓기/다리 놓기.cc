#include <iostream>

using namespace std;

double factorial(double n)
{
	if (n == 0)
		return 1;

	double result = 1;
	for (int i = 1; i <= n; i++)
		result *= i;

	return result;
}

int main()
{
	int N, M, T;
	double result;
	cin >> T;
	cout << fixed;
	cout.precision(0);

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		result = factorial(M) / (factorial(double(M - N)) * factorial(N));
		cout << result << endl;
	}

	return 0;
}