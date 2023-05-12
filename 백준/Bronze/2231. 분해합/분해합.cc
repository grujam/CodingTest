#include <iostream>
#include <math.h>

#define PII pair<int, int>

using namespace std;

PII FindDigitandFirstDigit(int N)
{
	int retval = 0;
	int digit = 0;
	while(N != 0)
	{
		N /= 10;
		retval = N;
		digit++;
	}
	return PII(retval, digit);
}

int DigitSum(int num)
{
	int sum = 0;
	while(num != 0)
	{
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

int FindLeastConstructor(int startNumber, int target)
{
	while(startNumber < target)
	{
		if (startNumber + DigitSum(startNumber) == target)
			return startNumber;
		startNumber++;
	}

	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	PII digitPair = FindDigitandFirstDigit(N);

	int startNumber;

	if(digitPair.first == 1)
	{
		startNumber = pow(10, digitPair.second-1);
	}
	else
	{
		startNumber = pow(digitPair.first - 1, digitPair.second-1);
	}

	cout << FindLeastConstructor(startNumber, N);


	return 0;
}