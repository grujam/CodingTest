#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, X;
    cin >> N >> X;

    queue<int> q;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if(num < X)
        {
            q.push(num);
        }
    }

    while(!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}