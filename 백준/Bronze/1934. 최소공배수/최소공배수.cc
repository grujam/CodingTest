#include <iostream>
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, A, B;

	cin >> T;
	for(int i = 0; i < T;i++)
	{
		cin >> A >> B;
		cout << lcm(A, B) << "\n";
	}



	return 0;
}