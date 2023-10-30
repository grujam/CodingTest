#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    stringstream ss;

    getline(cin, s);
    ss.str(s);

    int num = 0;

    while (ss >> s)
        num++;

    cout << num;

    return 0;
}