#include <iostream>

using namespace std;

int arr[8];

int N, M;

void NM(int cnt)
{
    if (cnt == M)
    {
        for (int i = 1; i < M + 1; i++)
            cout << arr[i] << " ";
        cout << '\n';

        return;
    }

    for (int i = 1; i < N + 1; i++)
    {
        arr[cnt + 1] = i;
        NM(cnt + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> N >> M;

    NM(0);

    return 0;
}