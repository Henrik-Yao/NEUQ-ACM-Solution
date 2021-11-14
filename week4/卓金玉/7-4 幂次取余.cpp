#include <bits/stdc++.h>
using namespace std;
long long fastPow(long long base, long long expo, long long mod);
int main()
{
    int T;
    long long a, b, c;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("%lld\n", fastPow(a, b, c));
    }
    return 0;
}
long long fastPow(long long base, long long expo, long long mod)
{
    long long re = 1;
    while (expo > 0)
    {
        if (expo & 1)
            re = re * base % mod;
        expo >>= 1;
        base = (base * base) % mod;
    }
    return re;
}