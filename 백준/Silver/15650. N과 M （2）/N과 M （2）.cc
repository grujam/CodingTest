#include <iostream>
#include <vector>

bool visited[9];
int arr[9];

int N, M;

using namespace std;

void NM(int n, int cnt)
{
    if (cnt == M)
    {
        for (int i = 1; i < M + 1; i++)
            cout << arr[i] << " ";
        cout << '\n';

        return;
    }

    for (int i = n + 1; i < N + 1; i++)
    {
        if (visited[i] == true)
            continue;

        visited[i] = true;
        arr[cnt + 1] = i;
        NM(i, cnt + 1);
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i < N + 1; i++)
    {
        visited[i] = true;
        arr[1] = i;
        NM(i, 1);
        visited[i] = false;
    }

    return 0;
}