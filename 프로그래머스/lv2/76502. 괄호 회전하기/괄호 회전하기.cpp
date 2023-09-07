#include <string>
#include <vector>
#include <stack>

using namespace std;

bool Check(string& s)
{
    stack<int> si;
    for(int i = 0; i < s.length(); i++)
    {
        switch(s[i])
        {
        case '(':
            si.push(0);
            break;
        case '[':
            si.push(1);
            break;
        case '{':
            si.push(2);
            break;
        case ')':
            if(si.empty() || si.top() != 0)
                return false;
            si.pop();
            break;
        case ']':
            if(si.empty() || si.top() != 1)
                return false;
            si.pop();
            break;
        case '}':
            if(si.empty() || si.top() != 2)
                return false;
            si.pop();
        }
    }
    
    if(si.empty())
        return true;
    return false;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i < s.length()-1; i++)
    {
        if(Check(s))
            answer++;
        
        char c = s[0];
        s.erase(0,1);
        s += c;
    }
    
    return answer;
}