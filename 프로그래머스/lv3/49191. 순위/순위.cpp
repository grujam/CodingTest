#include <string>
#include <vector>

#define WIN 1
#define LOSE -1
#define BLANK 0

using namespace std;

int result[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

	for (auto v : results)
	{
		result[v[0]][v[1]] = WIN;
		result[v[1]][v[0]] = LOSE;
	}

    for(int i = 1; i < n+1; i++)
    {
	    for(int j = 1; j < n+1; j++)
	    {
			for(int k = 1; k < n+1; k++)
			{
				if (result[i][j] != BLANK && result[i][j] == result[j][k])
                {
                    result[i][k] = result[i][j];
                    result[k][i] = result[j][i];
                }

			}
	    }
    }

	for(int i = 1; i < n+1; i++)
	{
		bool blank = false;
		for(int j = 1; j < n+1; j++)
		{
			if (i == j) continue;
			if (result[i][j] == BLANK)
			{
				blank = true;
				break;
			}
		}
		if (!blank) answer++;
	}

    return answer;
}