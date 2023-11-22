#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long Digits[11];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, k, digit;
    cin >> N >> k;

    for(long long i = 1; i < 11; i++)
    {
        Digits[i] = Digits[i - 1] + i * 9 * (long long) pow(10, i-1);
        if (k <= Digits[i])
        {
            digit = static_cast<int>(i);
            break;
        }
    }

    int num = k - Digits[digit - 1];
    int offset = num % digit;
    num /= digit;

    num += pow(10, digit-1) - 1;

    if (offset == 0)
    {
        if (num > N)
        {
            cout << -1;
            return 0;
        }
        string str = to_string(num);
        cout << str[digit - 1];
    }
    else
    {
        num++;
        if (num > N)
        {
            cout << -1;
            return 0;
        }
        string str = to_string(num);
        cout << str[offset - 1];
    }

    return 0;
}