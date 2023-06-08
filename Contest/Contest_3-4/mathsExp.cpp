#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long power(long long base, long long exponent)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        long long a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;

        long long numerator = a * b - c - d / e + (f * g) * h;
        long long denominator = d + g - f + e / h - c * b;
        long long result = (numerator * power(denominator, MOD - 2)) % MOD;

        cout << result << endl;
    }

    return 0;
}
