#include <string>
#include <vector>
#include <tuple>

using namespace std;

#define PBB pair<bool, bool>


bool CheckInsert(int x, int y, bool type, const vector<vector<PBB>>& Building)
{
    //Pillar = 0, Beam = 1
    bool check = false;
    if(!type)
    {
        if(y > 0)
            check |= Building[x][y-1].first;
        if(x > 0)
            check |= Building[x-1][y].second;
        
        check |= Building[x][y].second;
        check |= ( y == 0);
    }
    else
    {
        if(y > 0)
        {
            check |= Building[x][y-1].first;
            if(x < Building.size() - 1)
                check |= Building[x+1][y-1].first;
        }
        
        if(x > 0 && x < Building.size() - 1)
            check |= (Building[x-1][y].second && Building[x+1][y].second);
        
        check |= ( y == 0);
    }
    
    return check;
}

bool CheckDelete(int x, int y, bool type, vector<vector<PBB>> tmp)
{
    !type ? tmp[x][y].first = false : tmp[x][y].second = false;
    
    bool check = true;
    for(int i = x - 1; i < x + 2; i++)
    {
        for(int j = y - 1; j < y + 2; j++)
        {
            if(i < 0 || i > tmp.size() - 1 || j < 0 || j > tmp.size() - 1)
                continue;
            
            if(tmp[i][j].first)
                check &= CheckInsert(i,j,false,tmp);
            
            if(tmp[i][j].second)
                check &= CheckInsert(i,j,true,tmp);
        }
    }
    
    return check;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    //first = Pillar, second = Beam
    vector<vector<PBB>> Building(n+1, vector<PBB>(n+1, PBB(false, false)));
    
    for(vector<int>& v : build_frame)
    {
        //Delete = 0, Insert = 1
        if(v[3] && CheckInsert(v[0], v[1], v[2], Building))
            !v[2] ? Building[v[0]][v[1]].first = true : Building[v[0]][v[1]].second = true;
        else if (!v[3] && CheckDelete(v[0], v[1], v[2], Building))
            !v[2] ? Building[v[0]][v[1]].first = false : Building[v[0]][v[1]].second = false;
    }
    
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if(Building[i][j].first)
            {
                vector<int> v = {i,j,0};
                answer.emplace_back(v);
            }
            if(Building[i][j].second)
            {
                vector<int> v = {i,j,1};
                answer.emplace_back(v);
            }
        }
    }
    
    return answer;
}