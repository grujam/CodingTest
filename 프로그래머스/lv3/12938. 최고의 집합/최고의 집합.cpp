#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s)
    {
        answer.push_back(-1);
        return answer;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            answer.push_back(s/n);
        }
        int mod = s % n;
        for(int j = 0; j < mod; j++)
        {
            answer[n-1-j]++;
        }
    }
    return answer;
}