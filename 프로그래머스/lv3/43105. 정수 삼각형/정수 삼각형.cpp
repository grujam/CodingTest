#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int table[500][500];

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    table[0][0] = triangle[0][0];
    
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            if(j == 0)
                table[i][j] = table[i-1][j] + triangle[i][j];
            else if (j == i)
                table[i][j] = table[i-1][j-1] + triangle[i][j];
            else
            {
                table[i][j] = triangle[i][j] + max(table[i-1][j-1], table[i-1][j]);
            }
        }
    }
    
    int answer = 0;
    for(int k = 0; k < n; k++)
    {
        if(answer < table[n-1][k])
            answer = table[n-1][k];
    }
    
    return answer;
}