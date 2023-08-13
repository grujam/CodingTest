#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    
    for(int i = 1; i < n / 2 + 1; i++)
    {
        int total = 0;
        for(int j = i; j < n; j++)
        {
            total += j;
            if(total == n)
            {
                answer++;
                break;
            }
            else if(total > n)
                break;
        }
    }
    
    return answer;
}