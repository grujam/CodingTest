#include <iostream>
#include <math.h>

#define INF 9999999

using namespace std;

bool bBroken[10];

int GetDigits(int n)
{
	int digit = 0;
	if (n == 0)
		return 1;
	while(n > 0)
	{
		n /= 10;
		digit++;
	}

	return digit;
}

bool CheckDigits(int N)
{
	int digits = 0;
	if (N == 0)
		return !bBroken[0];
	while(N > 0)
	{
		int digit = N % 10;
		if (bBroken[digit])
			return false;
		digits++;
		N /= 10;
	}

	return true;
}

int GetSmaller(int N)
{
	int num = N;
	while(!CheckDigits(num) && num > -1)
	{
		num--;
	}
	if (num == -1)
		return INF;
	return N - num + GetDigits(num);
}

int GetBigger(int N)
{
	int num = N;
	while (!CheckDigits(num))
	{
		num++;
	}

	return num - N + GetDigits(num);
}

bool OnlyZero()
{
	if (bBroken[0] == true)
		return false;
	else
	{
		for(int i = 1; i < 10; i++)
		{
			if (bBroken[i] == false)
				return false;
		}
	}

	return true;
}

int FromHundred(int N)
{
	if (N > 100)
		return N - 100;
	else
		return 100 - N;
}

bool AllZero()
{
	for(int i = 0; i < 10; i++)
	{
		if (bBroken[i] == false)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N, M, ans = INF;

	cin >> N >> M;

	for(int i = 0; i < M ; i++)
	{
		int broken;

		cin >> broken;
		bBroken[broken] = true;
	}

	if (N == 100)
	{
		cout << 0;
		return 0;
	}
	else if (M == 0)
		ans = GetDigits(N);


	if (OnlyZero())
	{
		ans = N + 1;
		ans = min(N + 1, FromHundred(N));
		cout << ans;
		return 0;
	}
	else if (AllZero())
	{
		if (N > 100)
			cout << N - 100;
		else
			cout << 100 - N;
		return 0;
	}

	ans = min(ans, GetSmaller(N));
	ans = min(ans, GetBigger(N));
	if(N > 100)
		ans = min(ans, N - 100);
	else
		ans = min(ans, 100 - N);
	cout << ans;




	return 0;
}