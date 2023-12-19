#include <iostream>

using namespace std;

int dp[2502];
bool check[2502][2502];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string str;
    cin >> str;

    int s = str.size();

    str = " " + str;

    for (int i = 0; i <= s; i++)
    {
        check[i][i] = true;
        check[i][i + 1] = str[i] == str[i + 1];
    }

    for(int i = s - 2; i >= 0; i--)
    {
	    for(int j = i + 2; j <= s; j++)
	    {
            check[i][j] = check[i + 1][j - 1] & (str[i] == str[j]);
	    }
    }

    dp[1] = 1;
    dp[2] = check[1][2] ? 1 : 2;

    for(int i = 3; i <= s; i++)
    {
        dp[i] = dp[i - 1] + 1;
	    for(int j = 1; j < i; j++)
	    {
            if (check[j][i])
            {
                dp[i] = min(dp[i], dp[j-1] + 1);
            }
	    }
    }

    cout << dp[s];

    return 0;
}