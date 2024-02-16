#include <iostream>
#include <stack>

using namespace std;

#define PII pair<int, int>

int arr[500001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    stack<int> s1;
    stack<PII> s2;

    int cnt = 0, top = 0;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        s1.push(num);
    }

    s2.emplace(s1.top(), N);
    s1.pop();

    while(!s1.empty())
    {
        int cur = s1.top();
        s1.pop();

        int s = s1.size();
        while(!s2.empty() && cur > s2.top().first)
        {
            arr[s2.top().second] = s + 1;
            s2.pop();
        }
        s2.emplace(cur, s + 1);
    }

    for (int i = 1; i < N+1; i++)
        cout << arr[i] << ' ';

    return 0;
}
