#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq_greater;
    priority_queue<int, vector<int>, less<>> pq_less;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        pq_greater.push(num);
        pq_less.push(num);
    }

    cout << pq_greater.top() << " " << pq_less.top();

    return 0;
}