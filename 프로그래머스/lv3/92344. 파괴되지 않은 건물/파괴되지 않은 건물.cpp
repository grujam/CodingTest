#include <string>
#include <vector>

int CumSum[1002][1002];

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int N = board.size();
    int M = board[0].size();

    for(auto& s : skill)
    {
        if (s[0] == 1)
            s[5] = -s[5];

        CumSum[s[1]][s[2]] += s[5];
        CumSum[s[3]+1][s[4]+1] += s[5];
        CumSum[s[1]][s[4]+1] -= s[5];
        CumSum[s[3]+1][s[2]] -= s[5];
    }

    for(int i = 0; i < N+1; i++)
    {
	    for(int j = 1; j < M+1; j++)
	    {
            CumSum[i][j] += CumSum[i][j - 1];
	    }
    }
    
    for(int i = 1; i < N+1; i++)
    {
	    for(int j = 0; j < M+1; j++)
	    {
            CumSum[i][j] += CumSum[i-1][j];
	    }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] + CumSum[i][j] > 0)
                answer++;
        }
    }

    return answer;
}