#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int chess[11][11];

bool DownDiagonal[19];
bool UpDiagonal[19];

int ansBlack, ansWhite, N, B, W;

void FindBlack(vector<PII>& Black, int cnt, int idx)
{
    if (idx == B)
    {
        ansBlack = max(cnt, ansBlack);
        return;
    }

	PII black = Black[idx];

	if (!DownDiagonal[black.first + black.second] && !UpDiagonal[black.first - black.second + N - 1])
	{
		DownDiagonal[black.first + black.second] = true;
		UpDiagonal[black.first - black.second + N - 1] = true;
		FindBlack(Black, cnt + 1, idx + 1);
		UpDiagonal[black.first - black.second + N - 1] = false;
		DownDiagonal[black.first + black.second] = false;
	}

    FindBlack(Black, cnt, idx + 1);
}

void FindWhite(vector<PII>& White, int cnt, int idx)
{
    if(idx == W)
    {
        ansWhite = max(cnt, ansWhite);
        return;
    }

	PII white = White[idx];

	if (!DownDiagonal[white.first + white.second] && !UpDiagonal[white.first - white.second + N - 1])
	{
		DownDiagonal[white.first + white.second] = true;
		UpDiagonal[white.first - white.second + N - 1] = true;
		FindWhite(White, cnt + 1, idx + 1);
		UpDiagonal[white.first - white.second + N - 1] = false;
		DownDiagonal[white.first + white.second] = false;
	}

    FindWhite(White, cnt, idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //합이 짝수면 Black, 홀수면 White
    vector<PII> Black;
    vector<PII> White;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> chess[i][j];

            if(chess[i][j] == 1)
            {
                ((i + j) % 2 == 0) ? Black.emplace_back(i, j) : White.emplace_back(i, j);
            }
        }
    }

    B = Black.size();
    W = White.size();

    FindBlack(Black, 0, 0);
    FindWhite(White, 0, 0);

    cout << ansBlack + ansWhite;

    return 0;
}
