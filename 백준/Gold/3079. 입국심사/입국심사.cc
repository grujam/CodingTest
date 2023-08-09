#include <iostream>
#include <unordered_map>

#define PLL pair<unsigned long long, unsigned long long>

using namespace std;

bool Check(unsigned long long mid, const unsigned long long& M, const unordered_map<unsigned long long, unsigned long long>& m)
{
    unsigned long long cnt = 0;

    for(PLL pll : m)
    {
        cnt += (mid / pll.first) * pll.second;
        if (cnt >= M)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    unordered_map<unsigned long long, unsigned long long> m;

    unsigned long long N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        unsigned long long num;
        cin >> num;
        m[num]++;
    }

    unsigned long long low = 0, high = 1000000000000000000;

    while(low + 1 < high)
    {
        unsigned long long mid = (low + high) / 2;

        if (Check(mid, M, m))
            high = mid;
        else
            low = mid;
    }

    cout << high;

    return 0;
}