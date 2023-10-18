#include <string>
#include <vector>

using namespace std;

int FindLeft(int idx, string& name, int& answer)
{
    int left = idx - 1;
    int num = 1;

    if (left < 0)
        left = name.length() - 1;

    while (left != idx)
    {
        if (name[left] != 'A')
        {
            name[left] = 'A';
            answer += num;
            return left;
        }

        left--; num++;

        if (left < 0)
            left = name.length() - 1;
    }
    return idx;
}

int FindRight(int idx, string& name, int& answer)
{
    int right = idx + 1;
    int num = 1;

    if (right > name.length() - 1)
        right = 0;

    while (right != idx)
    {
        if (name[right] != 'A')
        {
            name[right] = 'A';
            answer += num;
            return right;
        }

        right++; num++;

        if (right > name.length() - 1)
            right = 0;
    }
    return idx;
}

int FindClosestAlphabet(int idx, string& name, int& answer)
{
    int left = idx - 1;
    int right = idx + 1;
    int num = 1;

    if (left < 0)
        left = name.length() - 1;
    if (right > name.length() - 1)
        right = 0;
    
    while (left != idx && right != idx)
    {
        if (name[left] != 'A')
        {
            name[left] = 'A';
            answer += num;
            return left;
        }
        if (name[right] != 'A')
        {
            name[right] = 'A';
            answer += num;
            return right;
        }

        left--; right++; num++;

        if (left < 0)
            left = name.length() - 1;
        if (right > name.length() - 1)
            right = 0;
    }
    return idx;
}

int solution(string name) {
    int answer = 0;
    int idx = 0;
    int idx2 = 0;

    string name2 = name;

    for (int i = 0; i < name.length(); i++)
    {
        int num = 31;
        num &= name[i];

        answer += min(num - 1, 26 - num + 1);
    }

    name[0] = 'A';
    name2[0] = 'A';

    int left = 0;
    int right = 0;

    int retVal1 = FindLeft(idx, name, left);
    int retVal2 = FindRight(idx2, name2, right);

    while (idx != retVal1)
    {
        idx = retVal1;
        retVal1 = FindClosestAlphabet(idx, name, left);
    }
    
    while (idx2 != retVal2)
    {
        idx2 = retVal2;
        retVal2 = FindClosestAlphabet(idx2, name2, right);
    }

    answer += min(left, right);

    return answer;
}