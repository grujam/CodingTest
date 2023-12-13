#include <iostream>

using namespace std;

int Solution[100001];

void Refresh(int& start, int& end, int& ans1, int& ans2, int& sum, int& summation)
{
	if(abs(sum) > abs(summation))
	{
        sum = summation;
        ans1 = start;
        ans2 = end;
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> Solution[i];

    int start = 0, end = N - 1, sum = 2147483647, summation = 0;
    int ans1 = start, ans2 = end;

    while(start < end)
    {
        summation = Solution[start] + Solution[end];

        Refresh(start, end, ans1, ans2, sum, summation);

        if (summation == 0)
            break;

        if (summation > 0)
            end--;
        else
            start++;
    }

    cout << Solution[ans1] << ' ' << Solution[ans2];

    return 0;
}