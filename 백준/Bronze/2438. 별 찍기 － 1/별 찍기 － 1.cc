#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    string s = "*";

    for(int i = 0; i < N; i++)
    {
        cout << s << '\n';
        s += "*";
    }

    return 0;
}