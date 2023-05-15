#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	double x = ((c * e - b * f) / (a * e - b * d));
	double y = ((-c * d + a * f) / (a * e - b * d));

	cout << (int)x << " " << (int)y;

	return 0;
}