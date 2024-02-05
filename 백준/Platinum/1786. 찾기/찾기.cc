#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> makepi(string str)
{
    int m = str.length();
    int j = 0;

    vector<int> pi(m, 0);

    for(int i = 1; i < m; i++)
    {
        while (j > 0 && str[i] != str[j])
            j = pi[j - 1];
        if (str[i] == str[j])
            pi[i] = ++j;
    }

    return pi;
}

vector<int> KMP(const string& Findee, const string& Finder, const vector<int>& pi)
{
    int j = 0;
    int fdeesize = Findee.size();
    int fdersize = Finder.size();

    vector<int> ret;

    for(int i = 0; i < Findee.length(); i++)
    {
        while (j > 0 && Findee[i] != Finder[j])
            j = pi[j - 1];
        if(Findee[i] == Finder[j])
        {
            if (j == fdersize - 1)
            {
                ret.push_back(i - fdersize + 2);
                j = pi[j];
            }
            else
                ++j;
        }
			
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string Finder, Findee;
    getline(cin, Findee);
    getline(cin, Finder);

    vector<int> ans = KMP(Findee, Finder, makepi(Finder));

    cout << ans.size() << '\n';

    for(int& i : ans)
    {
        cout << i << '\n';
    }

    return 0;
}
