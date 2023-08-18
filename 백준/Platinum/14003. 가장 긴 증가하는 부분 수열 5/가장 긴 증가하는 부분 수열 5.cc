#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int dp[1000001];
int nums[1000001];
int arr[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int N, length = 0;
    cin >> N;

    for (int i = 1; i < N + 1; i++)
    {
        cin >> nums[i];

        auto iter = lower_bound(arr, arr + length, nums[i]);
        *iter = nums[i];

        if (iter == arr + length)
        {
            length++;
        }
        dp[i] = iter - arr + 1;
    }

    stack<int> s;
    cout << length << endl;

    for (int i = N; i > 0; i--)
    {
        if (length == dp[i])
        {
            s.push(nums[i]);
            length--;
        }
    }
    while (!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }


    return 0;
}