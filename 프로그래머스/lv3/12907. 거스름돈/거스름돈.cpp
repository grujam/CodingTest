#include <string>
#include <vector>

using namespace std;

int dp[101][100001];

int solution(int n, vector<int> money) {
    int answer = 0;

    dp[0][0] = 1;

    for(int i = 0; i <= n; i++)
    {
        if (i % money[0] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }

    for(int i = 1; i < money.size(); i++)
    {
	    for(int j = 0; j <= n; j++)
	    {
            if (j - money[i] >= 0)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - money[i]]) % 1000000007;
            else
                dp[i][j] = dp[i - 1][j];
	    }
    }

    answer = dp[money.size() - 1][n];

    return answer;
}