#include <iostream>

using namespace std;

int Pages[502];
int Sum[502];
int DP[502][502];

#define INF 2147483647

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        int K;
        cin >> K;

        for(int i = 1; i <= K; i++)
        {
            cin >> Pages[i];
            Sum[i] = Sum[i - 1] + Pages[i];
        }

        for(int j = 1; j < K; j++)
        {
	        for(int i = 1; i <= K - j; i++)
	        {
                DP[i][i + j] = INF;
		        for(int k = i; k < i+j; k++)
		        {
                    DP[i][i + j] = min(DP[i][i + j], DP[i][k] + DP[k + 1][i + j] + Sum[i + j] - Sum[i - 1]);
		        }
	        }
        }

        cout << DP[1][K] << '\n';
    }


    return 0;
}