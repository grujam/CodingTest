#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int Works[1500002];
int dp[1500052];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i = 1; i < N + 1; i++)
    {
        int T, P;
        cin >> T >> P;

        dp[i + T - 1] = max(dp[i + T - 1], dp[i - 1] + P);
        dp[i] = max(dp[i], dp[i - 1]);
    }
    
    cout << dp[N];

    return 0;
}