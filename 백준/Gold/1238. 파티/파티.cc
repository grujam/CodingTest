#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    vector<vector<int>> dist(N+1, vector<int>(N+1, 10000000));

    for(int i = 0; i < M; i++)
    {
        int start, dest, weight;
        cin >> start >> dest >> weight;

        dist[start][dest] = weight;
    }

    for(int i = 1; i < N+1; i++)
    {
	    for(int j = 1; j < N+1; j++)
	    {
		    for(int k = 1; k < N+1; k++)
		    {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
		    }
	    }
    }

    int answer = 0;

    for(int i = 1; i < N+1; i++)
    {
        if (i == X)
            continue;
        answer = max(answer, dist[i][X] + dist[X][i]);
    }

    cout << answer;

    return 0;
}