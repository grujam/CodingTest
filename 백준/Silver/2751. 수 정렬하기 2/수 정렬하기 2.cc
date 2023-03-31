#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, tmp, i, j;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(begin(arr), begin(arr) + n);

	for (i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}