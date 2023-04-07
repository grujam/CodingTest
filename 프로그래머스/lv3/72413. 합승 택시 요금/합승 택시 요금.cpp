#include <string>
#include <vector>
#include <algorithm>

#define INF 9999999
#define PII pair<int, int>
#define Floyd_Warshall

using namespace std;

#ifdef Floyd_Warshall
class FloydWarshall
{
public:
	FloydWarshall(int node, int vertex)
	{
		this->node = node;
		distance = vector<vector<int>>(node, vector<int>(node, INF));
		vertices = vector<vector<PII>>(node, vector<PII>());

		for(int i = 0; i < node; i++)
		{
			distance[i][i] = 0;
		}
	}

	~FloydWarshall()
	{
		distance.clear();
		distance.shrink_to_fit();

		vertices.clear();
		vertices.shrink_to_fit();

		node = 0;
	}

	void InsertVertex(int src, int dest, int weight)
	{
		vertices[src-1].push_back(PII(dest-1, weight));
		distance[src-1][dest-1] = weight;
		distance[dest-1][src-1] = weight;
	}

	void Execute()
	{
		for(int k = 0; k < node; k++)
		{
			for(int i = 0; i < node; i++)
			{
				for(int j = 0; j < node; j++)
				{
					distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
				}
			}
		}
	}

	vector<vector<int>> GetDistance()
	{
		return distance;
	}

	vector<vector<PII>> GetVertices()
	{
		return vertices;
	}

	int GetNode()
	{
		return node;
	}

private:
	vector<vector<int>> distance;
	vector<vector<PII>> vertices;
	int node;
};
#endif


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    FloydWarshall fw(n, fares.size());

    for (int i = 0; i < fares.size(); i++)
    {
        fw.InsertVertex(fares[i][0], fares[i][1], fares[i][2]);
    }

    fw.Execute();

    vector<vector<int>> v = fw.GetDistance();

    for (int i = 0; i < n; i++)
    {
        answer = min(answer, v[i][a - 1] + v[i][b - 1] + v[i][s - 1]);
    }

    return answer;
}
