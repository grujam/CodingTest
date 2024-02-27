#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.length();
    
    int maxlen = s.length() / 2;
    
    for(int i = 1; i <= maxlen; i++)
    {
        string str = s.substr(0, i);
        int cnt = 0, tmp = 0;
        for(int j = 0; j + i <= s.length(); j += i)
        {
            string cur = s.substr(j, i);
            if(cur == str)
                cnt++;
            else
            {
                if(cnt == 1)
                    tmp += i;
                else
                {
                    string num = to_string(cnt);
                    tmp += i + num.length();
                }
                    
                cnt = 1;
                str = cur;
            }
        }
        
        if(cnt == 1)
            tmp += i;
        else if(cnt > 0)
        {
            string num = to_string(cnt);
            tmp += i + num.length();
        }
            
        tmp += (s.length() % i);
        
        answer = min(answer, tmp);
    }
    
    
    
    return answer;
}