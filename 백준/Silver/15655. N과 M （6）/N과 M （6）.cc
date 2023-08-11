#include <iostream>
#include <algorithm>

using namespace std;

int nums[9];
int arr[9];

int N, M;

void NM(int n, int cnt)
{
    if (cnt == M)
    {
        for (int i = 1; i < M + 1; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = n + 1; i < N + 1; i++)
    {
        arr[cnt + 1] = nums[i];
        NM(i, cnt + 1);
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i < N + 1; i++)
        cin >> nums[i];
    
    sort(nums + 1, nums + 1 +N);

    for (int i = 1; i < N+1; i++)
    {
        arr[1] = nums[i];
        NM(i, 1);
    }

    return 0;
}