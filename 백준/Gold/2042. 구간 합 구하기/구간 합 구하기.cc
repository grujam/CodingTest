#include <iostream>

using namespace std;

long long numbers[1000001];
long long sum[2097153];

int N, M, K;

void Sum(int idx, int start, int end)
{
    if(start == end)
    {
        sum[idx] = numbers[start];
        return;
    }

    int mid = (end + start) / 2;

    Sum(idx * 2, start, mid);
    Sum(idx * 2 + 1, mid+1, end);

    sum[idx] = sum[idx * 2] + sum[idx * 2 + 1];
}

void FindSum(int idx, int start, int end, int left, int right, long long& ans)
{
    if (end < left || start > right)
        return;

    if(left <= start && right >= end)
    {
        ans += sum[idx];
        return;
    }

    int mid = (start + end) / 2;

    FindSum(idx * 2, start, mid, left, right, ans);
    FindSum(idx * 2 + 1, mid+1, end, left, right, ans);
}

void FindIdx(const int& num, int idx, int start, int end, int& ret)
{
    if (start > num || end < num)
        return;

    if (start == end && start == num)
    {
        ret = idx;
        return;
    }

    int mid = (start + end) / 2;

    FindIdx(num, idx * 2, start, mid, ret);
    FindIdx(num, idx * 2 + 1, mid+1, end, ret);
}

void Change(int idx, long long num)
{
    long long delta = num - numbers[idx];
    numbers[idx] = num;
    int treeidx = 0;
    FindIdx(idx, 1, 1, N, treeidx);

    do
    {
        sum[treeidx] += delta;
        treeidx /= 2;
    } while (treeidx > 0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 1; i < N+1; i++)
        cin >> numbers[i];

    Sum(1, 1, N);

    for(int i = 0; i < M+K; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        if(a == 1)
        {
            Change(b, c);
        }
        else
        {
            long long ans = 0;
            FindSum(1, 1, N, b, c, ans);
            cout << ans << '\n';
        }
    }


    return 0;
}
