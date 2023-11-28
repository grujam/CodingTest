#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define PII pair<int, int>

string arr[101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int M, N, answer = 0;
    cin >> M >> N;

    for(int i = 0; i < M; i++)
    {
        vector<PII> v(N);
	    for(int j = 0; j < N; j++)
	    {
            int num;
            cin >> num;

            v[j] = PII(num, j);
	    }

        sort(v.begin(), v.end(), [&](PII a, PII b) {return a.first < b.first; });
        auto it = unique(v.begin(), v.end(), [&](PII a, PII b) {return a.first == b.first; });
        v.erase(it, v.end());

        string s = "";
        for(int j = 0; j < v.size(); j++)
        {
            s += to_string(v[j].second);
        }
        
        arr[i] = s;
    }

    for(int i = 0; i < M - 1; i++)
    {
	    for(int j = i+1; j < M; j++)
	    {
            if (arr[i] == arr[j])
            {
                answer++;
            }
	    }
    }

    cout << answer;

    return 0;
}