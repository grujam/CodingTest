#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    
    for(auto& v : tangerine)
    {
        m[v]++;
    }
    
    vector<int> v;
    
    for(auto& ele : m)
    {
        v.emplace_back(ele.second);
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for(auto& ele : v)
    {
        answer++;
        k -= ele;
        if(k <= 0)
            break;
    }
    
    return answer;
}