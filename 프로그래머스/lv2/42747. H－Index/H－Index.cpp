#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int CuSum[10001];

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i = 0; i < citations.size(); i++)
        CuSum[citations[i]]++;
    
    for(int i = 1; i < 10001; i++)
        CuSum[i] = CuSum[i] + CuSum[i-1];
    
    for(int i = 1; i < 10001; i++)
    {
        int sum = CuSum[10000] - CuSum[i-1];
        if(sum >= i)
            answer = max(answer, i);
    }
    
    return answer;
}