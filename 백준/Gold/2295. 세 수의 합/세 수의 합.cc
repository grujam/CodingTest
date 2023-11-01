#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int Numbers[1001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    vector<int> v;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> Numbers[i];
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            v.emplace_back(Numbers[i] + Numbers[j]);

    sort(v.begin(), v.end());
    sort(Numbers, Numbers + N, [](int a, int b) {return a > b; });

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int low = 0, high = v.size(), num = Numbers[i] - Numbers[j];

            while(low + 1 < high)
            {
                int mid = (low + high) / 2;

                if (v[mid] > num)
                    high = mid;
                else
                    low = mid;
            }

            if(v[low] == num)
            {
                cout << Numbers[i];
                return 0;
            }
        }
    }

    return 0;
}