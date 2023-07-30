#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int ans, zeros;

void BinaryTransformation(string& s)
{
    ans++;
    
    int len = s.length();
    s.erase(remove(s.begin(), s.end(), '0'), s.end());
    int num = s.length();
    
    zeros += len - num;
    
    string retVal = "";
    while(num > 1)
    {
        if(num % 2 == 1)
            retVal = "1" + retVal;
        else
            retVal = "0" + retVal;
        
        num /= 2;
    }
    
    if(num == 1)
        retVal = "1" + retVal;
    
    s = retVal;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    while(s != "1")
    {
        BinaryTransformation(s);
    }
    
    answer.emplace_back(ans);
    answer.emplace_back(zeros);
    
    return answer;
}