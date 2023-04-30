#include <iostream>
#include <numeric>

using namespace std;


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

	int divi = gcd(num, den);

	num /= divi;
	den /= divi;

	cout << num << " " << den;

	return 0;
}