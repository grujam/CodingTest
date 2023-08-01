#include <iostream>
#include <vector>

#define PII pair<int, int>

using namespace std;

int dp[101][10000];
PII Programs[101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        int mem;
        cin >> mem;

        Programs[i].first = mem;
    }

    for(int i = 0; i < N; i++)
    {
        int cost;
        cin >> cost;

        Programs[i].second = cost;
    }

    int leastCost = 10000001;
    for(int i = 0; i <= 10000; i++)
    {
        if (Programs[0].second > i)
            continue;

        dp[0][i] = Programs[0].first;
    }

    if (Programs[0].first >= M)
        leastCost = Programs[0].second;

    for(int i = 1; i < N; i++)
    {
	    for(int j = 0; j <= 10000; j++)
	    {
            if (Programs[i].second > j)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - Programs[i].second] + Programs[i].first);
            if (dp[i][j] >= M)
                leastCost = min(leastCost, j);
	    }
    }

    cout << leastCost;

    return 0;
}