#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

using namespace std;

string low(const string& s)
{
    string retVal = "";
    for(int i = 0; i < s.size(); i++)
    {
        char c = tolower(s[i]);
        retVal += c;
    }
    
    return retVal;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0)
        return cities.size() * 5;
    
    list<string> cache;
    
    for(int i = 0; i < cities.size(); i++)
    {
        string city = low(cities[i]);
        auto iter = find(cache.begin(), cache.end(), city);
        if(iter == cache.end())
        {
            answer += 5;
            
            if(cache.size() >= cacheSize)
                cache.pop_front();
            
            cache.push_back(city);
        }
        else
        {
            answer += 1;
            string s = *iter;
            cache.erase(iter);
            cache.push_back(s);
        }
    }
    
    return answer;
}