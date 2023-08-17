#include <iostream>

using namespace std;

long long cnt[1000];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    long long N, M, sum = 0, ans = 0;
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;

        sum += num;

        cnt[sum % M]++;
    }

    for(int i = 0; i < M; i++)
    {
        ans += (cnt[i] - 1) * (cnt[i]) / 2;
    }

    ans = cnt[0] + ans;

    cout << ans;

    return 0;
}