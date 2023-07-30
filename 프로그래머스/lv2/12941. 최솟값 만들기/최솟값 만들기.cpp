#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    
    priority_queue<int> pqa;
    priority_queue<int, vector<int>, greater<>> pqb;
    
    for(int i = 0; i < A.size(); i++)
    {
        pqa.push(A[i]);
        pqb.push(B[i]);
        
    }
    
    while(!pqa.empty())
    {
        int a = pqa.top();
        int b = pqb.top();
        pqa.pop();
        pqb.pop();
        
        answer += a*b;
    }
    
    return answer;
}