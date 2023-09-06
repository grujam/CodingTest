#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define PII pair<int, int>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 1;
    
    vector<PII> time;
    
    for(auto& v : book_time)
    {
        int start = v[0][0]*60*10 + v[0][1]*60 + v[0][3]*10 + v[0][4];
        int end = v[1][0]*60*10 + v[1][1]*60 + v[1][3]*10 + v[1][4] + 10;
        
        time.emplace_back(start,end);
    }
    
    sort(time.begin(), time.end());
    
    priority_queue<int, vector<int>, greater<>> pq;
    pq.push(time[0].second);
    
    int room = 1;
    
    for(int i = 1; i < time.size(); i++)
    {
        while(!pq.empty())
        {
            int end = pq.top();
            if(time[i].first < end)
                break;
            
            pq.pop();
            room--;
        }
        
        pq.push(time[i].second);
        room++;
        answer = max(answer, room);
    }
    
    return answer;
}