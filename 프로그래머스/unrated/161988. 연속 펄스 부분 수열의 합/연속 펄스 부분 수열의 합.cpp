#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long OneSeq[500001];
long long NegOneSeq[500001];

long long dp[500001];
long long dpneg[500001];

long long solution(vector<int> sequence) {
    long long answer = -999999;

    int s = sequence.size();

    long long one = 1;

    for(int i = 0; i < s; i++)
    {
        OneSeq[i] = (long long)sequence[i] * one;
        NegOneSeq[i] = (long long)sequence[i] * one * -1;

        one *= -1;
    }

    dp[0] = OneSeq[0];
    dpneg[0] = NegOneSeq[0];

    for(int i = 1; i < s; i++)
    {
        dp[i] = max(dp[i - 1] + OneSeq[i], OneSeq[i]);
        dpneg[i] = max(dpneg[i - 1] + NegOneSeq[i], NegOneSeq[i]);

        long long biggerdp = max(dp[i], dpneg[i]);

        answer = max(answer, biggerdp);
    }
    
    if(s == 1)
        answer = max(dp[0], dpneg[0]);
    
    return answer;
}