#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	int N;
    cin >> N;

    int len = 0;

    for(int i = 0; i < N; i++)
    {
        int num;
    	cin >> num;

        auto iter = lower_bound(arr, arr + len, num);

        *iter = num;

        if (iter == arr + len)
            len++;
    }

    cout << len;

    return 0;
}