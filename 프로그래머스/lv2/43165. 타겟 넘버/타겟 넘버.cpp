#include <string>
#include <vector>

using namespace std;

int answer;

void sol(int idx, int sum, const int& lastIdx, const int& target, const vector<int>& numbers)
{
    if(idx == lastIdx)
    {
        if(sum == target)
            answer++;
        return;
    }
    idx++;
    
    sol(idx, sum + numbers[idx], lastIdx, target, numbers);
    sol(idx, sum - numbers[idx], lastIdx, target, numbers);
}

int solution(vector<int> numbers, int target) {
    
    sol(0, -numbers[0], numbers.size()-1, target, numbers);
    sol(0, numbers[0], numbers.size()-1, target, numbers);
    
    return answer;
}