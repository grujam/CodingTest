#include <vector>

using namespace std;

int MOD = 20170805;

enum
{
    LEFT = 0, UP
};

int solution(int m, int n, vector<vector<int>> city_map) {

//전역 변수를 내부에서 선언하지 않으면 오류 발생...
long long dp[501][501][2] = {0};

    int x = 0;
    while(city_map[x][0] != 1 && x < m)
    {
        dp[x++][0][UP] = 1;
    }

    int y = 0;
    while(city_map[0][y] != 1 && y < n)
    {
        dp[0][y++][LEFT] = 1;
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(city_map[i-1][j] == 0)
                dp[i][j][UP] += (dp[i-1][j][UP] + dp[i-1][j][LEFT]) % MOD;
            if(city_map[i][j-1] == 0)
                dp[i][j][LEFT] += (dp[i][j-1][UP] + dp[i][j-1][LEFT]) % MOD;
            if(city_map[i-1][j] == 2)
                dp[i][j][UP] += dp[i-1][j][UP] % MOD;
            if(city_map[i][j-1] == 2)
                dp[i][j][LEFT] += dp[i][j-1][LEFT] % MOD;
        }
    }

    return (dp[m-1][n-1][LEFT] + dp[m-1][n-1][UP]) % MOD;
}