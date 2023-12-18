#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

#define PII pair<int, int>

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    long long N, S, ans = 0;
    cin >> N >> S;

    vector<long long> v1;
    vector<long long> v2;
    unordered_map<long long, long long> m;

    for(int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;

        if (i < N / 2)
            v1.push_back(num);
        else
            v2.push_back(num);
    }

    if(v1.size() == 0)
    {
        if (v2[0] == S)
            cout << 1;
        else
            cout << 0;

        return 0;
    }

    queue<PII> q;
    
    for(int i = 0; i < v1.size(); i++)
    {
        q.emplace(v1[i], i);
    }

    while(!q.empty())
    {
        int curSum = q.front().first;
        int num = q.front().second;
        q.pop();

        m[curSum]++;

        for(int i = num+1; i < v1.size(); i++)
        {
            q.emplace(curSum + v1[i], i);
        }
    }

    for(int i = 0; i < v2.size(); i++)
    {
        q.emplace(v2[i], i);
    }

    while(!q.empty())
    {
        int curSum = q.front().first;
        int num = q.front().second;
        q.pop();

        if (curSum == S)
            ans++;
        ans += m[S - curSum];

        for(int i = num + 1; i < v2.size(); i++)
        {
            q.emplace(curSum + v2[i], i);
        }
    }

    cout << ans + m[S];

    return 0;
}