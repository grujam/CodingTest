#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[100001];

#define INF 1000000

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int length = INF;

    int N, S;
    cin >> N >> S;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int start = 0, end = 0, sum = arr[0], len = 1;

    while(start < N && end < N)
    {
	    if(sum >= S)
	    {
            sum -= arr[start];
            start++;
            length = min(length, len);
            len--;
	    }
        else
        {
            end++;
            len++;
            sum += arr[end];
        }

        if (length == 1)
            break;
    }

    cout << (length == INF ? 0 : length);

    return 0;
}