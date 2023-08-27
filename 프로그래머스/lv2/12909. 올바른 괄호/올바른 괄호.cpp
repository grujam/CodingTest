#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int cnt = 0;
    
    for(const char& c : s)
    {
        if(c == ')')
            cnt--;
        else
            cnt++;
        
        if(cnt < 0)
            return false;
    }
    
    if(cnt != 0)
        return false;

    return true;
}