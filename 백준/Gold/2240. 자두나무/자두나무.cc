#include <iostream>

using namespace std;

#define PII pair<int, int>

int arr[1001][2];
int dp[31][1001][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T, W;
    cin >> T >> W;

    int num, idx = 1;

    cin >> num;

    arr[idx][num-1]++;

    for(int i = 1; i < T; i++)
    {
        int tmp;
        cin >> tmp;

        if (num != tmp)
        {
            num = tmp;
            idx++;
        }

        arr[idx][num-1]++;
    }

    dp[0][0][0] = arr[0][0];
    for(int i = 1; i <= idx; i++)
    {
        dp[0][i][0] = dp[0][i-1][0] + arr[i][0];
    }

    int ans = dp[0][idx][0];

    for(int j = 1; j <= W; j++)
    {
        for (int i = 1; i <= idx; i++)
        {
            dp[j][i][0] = max(dp[j][i - 1][0], dp[j - 1][i - 1][1]) + arr[i][0];
            dp[j][i][1] = max(dp[j][i - 1][1], dp[j - 1][i - 1][0]) + arr[i][1];
        }

        ans = max(ans, max(dp[j][idx][0], dp[j][idx][1]));
    }
    
    cout << ans;

    return 0;
}