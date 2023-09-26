#include <string>
#include <vector>
#include <stack>

using namespace std;

bool IsPrime(long long n)
{
    if(n < 2)
        return false;
    for(long long i = 2; i*i <=n; i++)
    {
        if(n % i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    stack<long long> s;

    while (n > k)
    {
        s.push(n % k);
        n /= k;
    }
    if(n != 0)
        s.push(n);

    long long num = 0;
    while (!s.empty())
    {
        long long top = s.top();
        s.pop();

        if (top == 0)
        {
            if (num > 1)
            {
                if(IsPrime(num))
                    answer++;
            }

            num = 0;
            continue;
        }

        num = (num * 10) + top;
    }
    
    if(IsPrime(num))
        answer++;

    return answer;
}