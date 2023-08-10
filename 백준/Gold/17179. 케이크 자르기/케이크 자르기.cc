#include <iostream>
#include <vector>

using namespace std;

bool Check(const int& mid, const vector<int>& cuts, const int& q, const int& end)
{
    int bef = 0, cut = 0;

    for(const int& c : cuts)
    {
	    if(c - bef >= mid && end - c >= mid)
	    {
            bef = c;
            cut++;
	    }
    }

    if (cut < q)
        return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> cuts;

    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        cuts.emplace_back(num);
    }

    vector<int> Q;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        Q.emplace_back(num);
    }

    for(int q : Q)
    {
        int low = 1, high = L / 2 + 1;
        while(low + 1 < high)
        {
            int mid = (low + high) / 2;

            if (Check(mid, cuts, q, L))
                low = mid;
            else
                high = mid;
        }

        cout << low << '\n';
    }

    return 0;
}