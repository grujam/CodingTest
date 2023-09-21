#include <string>
#include <map>

using namespace std;

typedef pair<string, int> PSI;

void ToLower(char& c)
{
    if (c >= 'A' && c <= 'Z')
    {
        c += 32;
    }
}

bool NotAlphabet(char a, char b)
{
    if (a < 'a' || a > 'z')
        return true;
    if (b < 'a' || b > 'z')
        return true;

    return false;
}

int solution(string str1, string str2) {
    int answer = 65536;
    int inter = 0;

    map<string, int> m1;
    map<string, int> m2;

    for (int i = 0; i < str1.length() - 1; i++)
    {
        char c1 = str1[i];
        char c2 = str1[i + 1];
        ToLower(c1);
        ToLower(c2);

        if (NotAlphabet(c1, c2))
            continue;

        string s;
        s.push_back(c1); s.push_back(c2);

        m1[s]++;
    }

    for (int i = 0; i < str2.length() - 1; i++)
    {
        char c1 = str2[i];
        char c2 = str2[i + 1];
        ToLower(c1);
        ToLower(c2);

        if (NotAlphabet(c1, c2))
            continue;

        string s;
        s.push_back(c1); s.push_back(c2);

        m2[s]++;
    }

    map<string, int> uni = m1;

    for(PSI psi : m2)
    {
        uni[psi.first] = max(uni[psi.first], psi.second);

        if(m1.find(psi.first) != m1.end())
        {
            inter += min(m1[psi.first], m2[psi.first]);
        }
    }

    int un = 0;

    for(PSI psi : uni)
    {
        un += psi.second;
    }

    if (un == 0)
        return answer;

    answer = (inter * 65536) / un;

    return answer;
}