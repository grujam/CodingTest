#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int arr[1001];
int tmp[1001];
int dp1[1001];
int dp2[1001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int len = 0;
    for(int i = 0; i < N; i++)
    {
        auto iter = lower_bound(tmp, tmp + len, arr[i]);
        *iter = arr[i];

        if (iter == tmp + len)
            ++len;

        dp1[i] = len;
    }

    memset(tmp, 0, sizeof(tmp));

    len = 0;
    for(int i = N-1; i > -1; i--)
    {
        auto iter = lower_bound(tmp, tmp + len, arr[i]);
        *iter = arr[i];

        if (iter == tmp + len)
            ++len;

        dp2[i] = len;
    }

    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        ans = max(ans, dp1[i] + dp2[i] - 1);
    }


    cout << ans;
    return 0;
}