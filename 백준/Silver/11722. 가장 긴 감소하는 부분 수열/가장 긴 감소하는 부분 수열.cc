#include <iostream>
#include <algorithm>

using namespace std;

int arr[1001];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    fill(arr, arr + 1000, 9999);

	int N;
    cin >> N;

    int len = 1, tmp;

    cin >> tmp;
    arr[0] = tmp;

    for(int i = 1; i < N; i++)
    {
        int num, j;
    	cin >> num;

        for(j = 0; j < len+1; j++)
        {
            if (arr[j] <= num || j == len)
            {
				arr[j] = num;
                break;
            }
        }

        if (j == len)
        {
            len++;
        }
    }

    cout << len;

    return 0;
}