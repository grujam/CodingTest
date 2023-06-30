#include <iostream>

using namespace std;

bool isPrime(long long n)
{
	if (n == 0 || n == 1)
		return false;

	for(long long i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}

	return true;
}

long long FindNextPrimeNumber(long long n)
{
	long long num = n;
	while (!isPrime(num))
		num++;

	return num;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		long long num;
		cin >> num;

		cout << FindNextPrimeNumber(num) << "\n";
	}
	
	return 0;
}