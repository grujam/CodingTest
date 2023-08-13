#include <string>
#include <vector>

using namespace std;

int ones(int num)
{
    int retVal = 0;
    while(num > 2)
    {
        retVal += num % 2;
        num /= 2;
    }
    
    return retVal;
}

int solution(int n) {
    int answer = n+1;
    int val = ones(n);
    int check;
    while(answer <= 1000000)
    {
        check = ones(answer);
        if(val == check)
            return answer;
        
        answer++;
    }
    
    return answer;
}