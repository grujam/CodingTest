#include <iostream>
#include <math.h>

using namespace std;

void solution(int N)
{
	if (N == 0)
	{
		cout << "-";
		return;
	}

	int ln = pow(3, N - 1);

	solution(N - 1);
	for (int i = 0; i < ln; i++)
		cout << " ";
	solution(N - 1);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int N;
	while(cin >> N)
	{
		solution(N);
		cout << "\n";
	}

	return 0;
}