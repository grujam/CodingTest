#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> pq_min;
    priority_queue<int, vector<int>, less<>> pq_max;

    int num;
    cin >> num;
    pq_max.emplace(num);
    cout << pq_max.top() << '\n';

    for(int i = 1; i < N; i++)
    {
        cin >> num;

        if (pq_max.size() == pq_min.size())
            pq_max.emplace(num);
        else
            pq_min.emplace(num);

        
        if(pq_max.top() > pq_min.top())
        {
            int a = pq_max.top();
            pq_max.pop();
            int b = pq_min.top();
            pq_min.pop();

            pq_max.emplace(b);
            pq_min.emplace(a);
        }

        cout << pq_max.top() << '\n';
    }

    return 0;
}