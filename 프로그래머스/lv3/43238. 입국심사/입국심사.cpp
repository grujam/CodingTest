#include <iostream>
#include <vector>
#include <queue>

#define PLL pair<long long, long long>

using namespace std;

struct cmp
{
    bool operator()(PLL a, PLL b)
    {
        if( a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

long long solution(int n, vector<int> times) {
    long long answer = 0;
    priority_queue<PLL, vector<PLL>, cmp> pq;

    long long s = times.size();


    double personPerTime = 0.0;
    double approx = 0;

    for (int i = 0; i < s; i++)
        personPerTime += 1.0 / times[i];

    approx = static_cast<double>(n / personPerTime);

    long long cnt = 0;
    for (int i = 0; i < s; i++)
    {
        cnt = approx / times[i];
        pq.push(PLL(times[i] * (cnt+1), times[i]));
        n -= cnt;
    }

    while (n > 0)
    {
        long long total = pq.top().first;
        long long time = pq.top().second;
        pq.pop();

        answer = total;

        pq.push(PLL(total + time, time));
        n--;
    }


    return answer;
}