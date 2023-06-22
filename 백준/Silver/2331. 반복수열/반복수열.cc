#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;

int CalcNextElement(int n, int P)
{
	int sum = 0;
	while(n > 0)
	{
		sum += pow(n % 10, P);
		n /= 10;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int A, P, idx = 1;
	cin >> A >> P;

	vector<int> v;
	map<int, int> m;

	v.emplace_back(A);
	m.insert(make_pair(A, 0));

	while(true)
	{
		int nextElement = CalcNextElement(v[idx-1], P);

		v.emplace_back(nextElement);
		auto ret = m.insert(make_pair(nextElement, idx));

		idx++;

		if(ret.second == false)
		{
			cout << m[nextElement];
			break;
		}
	}
	
	return 0;
}