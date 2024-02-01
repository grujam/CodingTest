#include <string>
#include <vector>

using namespace std;

char arr[5][5];

int dirx[4] = {0, -1, 0, 1};
int diry[4] = {-1, 0, 1, 0};

int checkx[12] = {-1, 0, 1, -1, -2, -1, -1, 0, 1, 1, 2, 1};
int checky[12] = {-1, -2, -1, -1, 0, 1, 1, 2, 1, 1, 0, -1};

void AddToArray(const vector<string>& place)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            arr[i][j] = place[i][j];
        }
    }
}

bool Check(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        int newx = x + dirx[i];
        int newy = y + diry[i];
        
        if(newx >= 5 || newy >= 5 || newx < 0 || newy < 0)
            continue;
        
        if(arr[newx][newy] == 'P')
            return true;
    }
    
    for(int i = 0; i < 12; i++)
    {
        int newx = x + checkx[i];
        int newy = y + checky[i];
        int adjx = x + dirx[i/3];
        int adjy = y + diry[i/3];
        
        if(newx >= 5 || newy >= 5 || newx < 0 || newy < 0)
            continue;
        
        if(arr[newx][newy] == 'P' && arr[adjx][adjy] == 'O')
            return true;
    }
    
    
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(vector<string>& place : places)
    {
        AddToArray(place);
        bool check = false;
        
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(arr[i][j] == 'P' && check == false)
                {
                    check |= Check(i,j);
                }
            }
        }
        
        if(check)
            answer.push_back(0);
        else
            answer.push_back(1);
    }
    
    return answer;
}