#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    
    priority_queue<int, vector<int>, less<>> pq;
    
    for(; answer < enemy.size(); answer++)
    {
        if(enemy[answer] <= n)
        {
            pq.push(enemy[answer]);
            n -= enemy[answer];
        }
        else
        {
            if(k == 0)
                return answer;
            else
            {
                if(!pq.empty() && enemy[answer] < pq.top())
                {
                    n = n + pq.top() - enemy[answer];
                    pq.pop();
                    pq.push(enemy[answer]);
                }
                k--;
            }
        }
        
    }
    
    return answer;
}