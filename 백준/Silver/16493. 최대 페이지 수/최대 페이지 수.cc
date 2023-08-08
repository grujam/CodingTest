#include <iostream>
#define PII pair<int, int>

using namespace std;

int dp[20][200];
PII Chapters[20];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        int days, pages;
        cin >> days >> pages;

        Chapters[i] = PII(days, pages);
    }

    for(int i = 0; i <= N; i++)
    {
        if (i >= Chapters[0].first)
            dp[0][i] = Chapters[0].second;
    }

    for(int i = 1; i < M; i++)
    {
	    for(int j = 1; j <= N; j++)
	    {
            if (j < Chapters[i].first)
            {   
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - Chapters[i].first] + Chapters[i].second);
	    }
    }

    cout << dp[M - 1][N];

    return 0;
}