#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<int, int> m;

    for(int i = 1; i < 31; i++)
    {
        m[i]++;
    }

    for(int i = 0; i < 28; i++)
    {
        int num;
        cin >> num;

        m.erase(num);
    }

    for(pair<int, int> i : m)
    {
        cout << i.first << endl;
    }

    return 0;
}