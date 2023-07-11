#include <iostream>

using namespace std;

int arr[1001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N, len = 0;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		auto pos = lower_bound(arr + 1, arr + len + 1, num);
		*pos = num;

		if (pos == arr + len + 1)
			++len;
	}

	cout << len;

	return 0;
}