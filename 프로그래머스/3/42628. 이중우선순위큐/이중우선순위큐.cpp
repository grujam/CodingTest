#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int count = 0;
    
    priority_queue<int, vector<int>, greater<int>> min;
    priority_queue<int, vector<int>, less<int>> max;
    
    int n = operations.size();
    
    for(int i = 0; i < n; i++)
    {
        if(count == 0)
        {
            while(!max.empty())
                max.pop();
            while(!min.empty())
                min.pop();
        }
        if(operations[i][0] == 'I')
        {
            int input = stoi(operations[i].substr(2));
            max.push(input);
            min.push(input);
            count++;
        }
        else if((count > 0) && (operations[i][0] == 'D'))
        {
            if(operations[i][2] == '1')
                max.pop();
            else
                min.pop();
            count--;
        }

                             
    }
    if(count <= 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(max.top());
        answer.push_back(min.top());
    }
    
    return answer;
}