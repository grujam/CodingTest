#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>

#define PII pair<int, int>
#define TIII tuple<int, int, int>

using namespace std;

char arr[101][101];
bool visited[101][101];
bool doc[101][101];

int dirx[4] = { 0, -1, 0, 1 };
int diry[4] = { -1, 0, 1, 0 };

bool IsDoor(const char& c)
{
    if (c >= 'A' && c <= 'Z') 
        return true;
    return false;
}

bool IsKey(const char& c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        int h, w;
        cin >> h >> w;

        vector<PII> starting_points;
        int keys = 0;
        int documents = 0;

        for(int i = 0; i < h; i++)
	        for(int j = 0; j < w; j++)
                cin >> arr[i][j];

    	string keystr;
        cin >> keystr;

        if(keystr != "0")
        {
            for (int i = 0; i < keystr.length(); i++)
                keys |= 1 << (keystr[i] - 97);
        }

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (arr[i][j] != '*')
                {
                    starting_points.emplace_back(i, j);
                }
                if (i != 0 && i != h - 1)
                    j += w - 2;
            }
        }

        int tmpkeys = -1;
        int tmpdocuments = -1;

    	while(tmpkeys != keys || tmpdocuments != documents)
        {
            tmpkeys = keys;
            tmpdocuments = documents;

            for(int i = 0; i < starting_points.size(); i++)
            {
                queue<PII> q;
                q.push(starting_points[i]);
                
                memset(visited, false, sizeof(visited));

                visited[starting_points[i].first][starting_points[i].second] = true;

                while(!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    if (arr[x][y] == '$' && doc[x][y] == false)
                    {
                        documents++;
                        doc[x][y] = true;
                    }
                    else if (IsKey(arr[x][y]))
                        keys |= 1 << (arr[x][y] - 97);
                    else if (IsDoor(arr[x][y]) && ((keys | 1 << (arr[x][y] - 65)) != keys))
                        continue;

                    for(int i = 0; i < 4; i++)
                    {
                        int newx = x + dirx[i];
                        int newy = y + diry[i];

                        if (newx >= h || newx < 0 || newy >= w || newy < 0 || visited[newx][newy] == true || arr[newx][newy] == '*')
                            continue;

                        visited[newx][newy] = true;
                        q.emplace(newx, newy);
                    }
                }

            }
        }
        memset(doc, false, sizeof(doc));
        cout << documents << '\n';
    }

    return 0;
}
