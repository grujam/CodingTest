#include <iostream>
#include <cmath>

using namespace std;

long long cnt[11];
long long zero[11];
long long digits[11];
long long answer[10];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cnt[1] = 1;
    zero[1] = 0;

    // i자릿수 만들때 들어가는 숫자의 양
    for(long long i = 2; i < 11; i++)
    {
        cnt[i] = pow(10, i - 1) + cnt[i - 1] * 10;
        zero[i] = zero[i - 1] + (cnt[i-1] * 9);
    }

    long long N, tmp;
    cin >> N;

    tmp = N;

    // 자릿 수
    int dig = 1;

    // 자릿 수 계산 및 각 자릿 수 저장
    while(tmp > 0)
    {
        digits[dig] = tmp % 10;
        tmp /= 10;
        dig++;
    }

    dig--;

    //자릿수 - 1만큼 숫자 만들 때 드는 양
    answer[0] = zero[dig - 1];
    for(int i = 1; i < 10; i++)
        answer[i] = cnt[dig - 1];

    // 1의 자릿수에 따른 앞 자릿수 횟수 추가
    for(int i = 2; i <= dig; i++)
        answer[digits[i]] += digits[1] + 1;

    // 1의 자릿수에 따른 추가
    for (int i = 1; i <= digits[1]; i++)
        answer[i]++;

    if (dig != 1)
    {
        for (int i = digits[dig] - 1; i > 0; i--)
        {
            answer[i] += pow(10, dig - 1);
            for (int j = 0; j < 10; j++)
                answer[j] += cnt[dig - 1];
        }
        answer[0]++;
    }

    //2자릿수 부터
    for(int i = 2; i < dig; i++)
    {
        int num = digits[i];

        for(int j = i + 1; j <= dig; j++)
        {
            answer[digits[j]] += num * pow(10, i - 1);
        }

        for(int j = num - 1; j >= 0; j--)
        {
            answer[j] += pow(10, i - 1);

            for(int k = 0; k < 10; k++)
            {
                answer[k] += cnt[i - 1];
            }
        }
    }

    for (int i = 0; i < 10; i++)
        cout << answer[i] << " ";

    return 0;
}
