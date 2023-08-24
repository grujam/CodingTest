#include <iostream>
#include <vector>
#include <algorithm>

#define PII pair<int, int>

using namespace std;

int arr[100];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    vector<PII> v;

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int a, b;
        cin >> a >> b;

        v.emplace_back(a, b);
    }

    sort(v.begin(), v.end());

    int len = 0;
    for(int i = 0; i < N; i++)
    {
        auto iter = lower_bound(arr, arr + len, v[i].second);

        *iter = v[i].second;

        if (iter == arr + len)
            len++;
    }

    cout << N - len;

    return 0;
}