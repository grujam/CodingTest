#include<vector>
#include <queue>
#include <tuple>

#define INF 2147483647
#define TIII tuple<int, int, int>

bool visited[101][101];

int dirx[4] = {0,-1, 0, 1};
int diry[4] = {-1,0,1,0};

using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = INF;
    
    queue<TIII> q;
    visited[0][0] = true;
    q.emplace(0,0,1);
    
    while(!q.empty())
    {
        int curx = get<0>(q.front());
        int cury = get<1>(q.front());
        int dist = get<2>(q.front());
        q.pop();
        
        if(curx == maps.size()-1 && cury == maps[0].size() -1)
        {
            answer = dist;
            break;
        }
        
        for(int i = 0; i < 4; i++)
        {
            int newx = curx + dirx[i];
            int newy = cury + diry[i];
            
            if(newx < 0 || newx > maps.size() -1 || newy < 0 || newy > maps[0].size() -1 || visited[newx][newy] == true)
                continue;
            
            if(maps[newx][newy] == 0)
                continue;
            
            visited[newx][newy] = true;
            q.emplace(newx, newy, dist + 1);
        }
    }
    if(answer == INF)
        answer = -1;
    
    return answer;
}