#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    for(int i = 1; i < N; i++)
    {
        dp[i] = arr[i];
	    for(int j = i; j > -1; j--)
	    {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[i],dp[j] + arr[i]);
            }
	    }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(ans, dp[i]);

    cout << ans;

    return 0;
}