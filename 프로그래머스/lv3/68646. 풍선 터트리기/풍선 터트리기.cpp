#include <string>
#include <vector>
#include <queue>

#define INF 1000000001

using namespace std;

int LeftMin[10000001];
int RightMin[10000001];

int solution(vector<int> a) {
    int answer = 0;
    int left = INF, right = INF;
    for(int i = 0; i < a.size(); i++)
    {
        left = min(left, a[i]);
        LeftMin[i] = left;
    }

    for (int i = a.size()-1; i > -1; i--)
    {
        right = min(right, a[i]);
        RightMin[i] = right;
    }

    for(int i = 0; i < a.size(); i++)
    {
        if (i == 0 || i == a.size() - 1)
        {
            answer++;
            continue;
        }

        if (a[i] > LeftMin[i - 1] && a[i] > RightMin[i + 1])
            continue;
        answer++;
    }

    return answer;
}