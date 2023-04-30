#include <iostream>
#include <numeric>

using namespace std;

void Check(int &A, int &B)
{
	
	bool again = true;

	while (again)
	{
		if (B == 1)
			break;
		for (int i = 2; i <= B; i++)
		{
			if(A % i == 0 && B % i == 0)
			{
				A /= i;
				B /= i;
				again = true;
				break;
			}
			again = false;
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A1, B1, A2, B2;

	cin >> A1 >> B1 >> A2 >> B2;

	int den = lcm(B1, B2);

	A1 = A1 * (den / B1);
	A2 = A2 * (den / B2);

	int num = A1 + A2;

	Check(num, den);

	cout << num << " " << den;

	return 0;
}