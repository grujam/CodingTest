#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[131073];

int answer = 0;

void FloodFill(int bitmask, int sheeps, int wolves, vector<int> possibles, const vector<vector<int>>& connections, const vector<int>& info)
{
    for (int i : possibles)
    {
        int newBitmask = bitmask | (1 << i);
        int newSheeps = sheeps;
        int newWolves = wolves;
        vector<int> newPossibles = possibles;

        if (visited[newBitmask])
            continue;

        if (info[i] == 0)
            newSheeps++;
        else
            newWolves++;

        if (newSheeps <= newWolves)
            continue;

        newPossibles.erase(find(newPossibles.begin(), newPossibles.end(), i));
        visited[newBitmask] = true;

        for (int j : connections[i])
            newPossibles.push_back(j);

        FloodFill(newBitmask, newSheeps, newWolves, newPossibles, connections, info);
    }

	answer = max(answer, sheeps);
}

int solution(vector<int> info, vector<vector<int>> edges) {

    vector<vector<int>> connections(info.size());

    for (int i = 0; i < edges.size(); i++)
    {
        connections[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int> possibles;

    for (int i : connections[0])
    {
        possibles.push_back(i);
    }

    visited[1] = true;
    FloodFill(1, 1, 0, possibles, connections, info);

    return answer;
}
