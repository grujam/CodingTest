#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string, int> m;
    
    answer.emplace_back(0);
    answer.emplace_back(0);
    
    int cnt = 1;
    m[words[0]]++;
    
    while(cnt < words.size())
    {
        if(words[cnt][0] != words[cnt-1][words[cnt-1].length()-1] || m[words[cnt]] != 0)
        {
            answer[0] = cnt % n + 1;
            answer[1] = cnt / n + 1;
            break;
        }
        
        m[words[cnt]]++;
        cnt++;
    }

    return answer;
}