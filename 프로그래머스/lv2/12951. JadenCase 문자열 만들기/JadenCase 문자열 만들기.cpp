#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    char before = s[0];
    answer += toupper(before);
    for(int i = 1; i < s.length(); i++)
    {
        if(before == ' ')
            answer += toupper(s[i]);
        else
            answer += tolower(s[i]);
        
        before = s[i];
    }
    
    return answer;
}