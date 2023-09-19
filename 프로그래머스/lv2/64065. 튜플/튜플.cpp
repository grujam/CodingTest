#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define PII pair<int, int>

bool cmp(PII a, PII b)
{
    return a.second > b.second;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    map<int, int> m;
    
    int num = 0;
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if(c >= '0' && c <= '9')
        {
            num = (num*10) + (c-48);
        }
        else
        {
            if(num != 0)
            {
                m[num]++;
                num = 0;
            }
        }
    }
    
    vector<PII> v;
    for(PII pii : m)
    {
        v.emplace_back(pii);
    }

    sort(v.begin(), v.end(), cmp);    
    
    for(PII pii : v)
    {
        answer.emplace_back(pii.first);
    }
    
    return answer;
}