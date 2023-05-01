#include <iostream>
#include <math.h>

using namespace std;


int main()
{
	int T;

	cin >> T;

	double x1, y1, r1, x2, y2, r2, distance;

	for(int i = 0; i < T; i++)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		if (x1 == x2 && y1 == y2 && r1 == r2)
		{
			cout << -1 << endl;
			continue;
		}
		else if(x1 == x2 && y1 == y2 && r1 != r2)
		{
			cout << 0 << endl;
			continue;
		}

		distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		if(distance + r1 < r2 || distance + r2 < r1)
		{
			cout << 0 << endl;
			continue;
		}

		if(r1+r2 == distance || distance + r1 == r2 || distance + r2 == r1)
		{
			cout << 1 << endl;
			continue;
		}
		else if(r1+r2 > distance)
		{
			cout << 2 << endl;
			continue;
		}
		else
		{
			cout << 0 << endl;
		}
	}

	return 0;
}