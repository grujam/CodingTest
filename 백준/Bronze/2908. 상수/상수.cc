#include <iostream>

using namespace std;

int Reverse(int n)
{
	int num = 0;

	while(n > 0)
	{
		int a = n % 10;
		n /= 10;

		num = (num * 10) + a;
	}

	return num;
}

int ReverseCmp(int a, int b)
{
	int rev_a = Reverse(a);
	int rev_b = Reverse(b);

	if (rev_a > rev_b)
		return rev_a;
	else
		return rev_b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int a, b;
	cin >> a >> b;

	cout << ReverseCmp(a, b);

	return 0;
}