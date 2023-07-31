#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long A, B, C;

long long Recursive(long long B)
{
    if (B == 0)
        return 1;
    if (B == 1)
        return A % C;

    long long n = Recursive(B / 2) % C;

    if(B % 2 == 0)
		return n * n % C;

    return (n * n % C * A % C) % C;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;

    long long ans = Recursive(B);

    cout << ans;

    return 0;
}