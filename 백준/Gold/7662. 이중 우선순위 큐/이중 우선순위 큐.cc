#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int count = 0;

        priority_queue<int, vector<int>, greater<>> min;
        priority_queue<int, vector<int>, less<>> max;
        map<int, int> m;

        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            char c;
            int num;
            cin >> c >> num;
            
			if (count == 0)
			{
				while (!max.empty())
					max.pop();
				while (!min.empty())
					min.pop();
			}
            if (c == 'I')
            {
                m[num]++;
                max.push(num);
                min.push(num);
                count++;
            }
            else if ((count > 0) && (c == 'D'))
            {
                if (num == 1)
                {
                    while (!max.empty() && m[max.top()] == 0)
                        max.pop();
                    m[max.top()]--;
                    max.pop();
                }
                else
                {
                    while (!min.empty() && m[min.top()] == 0)
                        min.pop();
                    m[min.top()]--;
                    min.pop();
                }
                count--;
            }


        }
        if (count <= 0) {
            cout << "EMPTY\n";
        }
        else
        {
            while (m[max.top()] == 0)
                max.pop();
            while (m[min.top()] == 0)
                min.pop();
            cout << max.top() << " " << min.top() << "\n";
        }
    }
    

    return 0;
}