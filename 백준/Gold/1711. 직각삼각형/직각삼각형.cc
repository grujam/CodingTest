#include <iostream>

#define PLL pair<long long, long long>

using namespace std;

PLL dots[1501];

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> dots[i].first >> dots[i].second;

    int ans = 0;
    for(int i = 0; i < N-2; i++)
    {
	    for(int j = i+1; j < N - 1; j++)
	    {
		    for(int k = j+1; k < N; k++)
		    {
                long long line1 = (dots[i].first - dots[j].first) * (dots[i].first - dots[j].first) + (dots[i].second - dots[j].second) * (dots[i].second - dots[j].second);
                long long line2 = (dots[i].first - dots[k].first) * (dots[i].first - dots[k].first) + (dots[i].second - dots[k].second) * (dots[i].second - dots[k].second);
                long long line3 = (dots[j].first - dots[k].first)*(dots[j].first - dots[k].first) + (dots[j].second - dots[k].second)*(dots[j].second - dots[k].second);
                if (line1 + line2 == line3 || line1 + line3 == line2 || line2 + line3 == line1)
                    ans++;
		    }
	    }
    }

    cout << ans;

    return 0;
}