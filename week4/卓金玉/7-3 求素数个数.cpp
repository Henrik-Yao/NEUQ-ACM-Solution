#include <bits/stdc++.h>
#define MAXN 100   // pre-calc max n for phi(m, n)
#define MAXM 10010 // pre-calc max m for phi(m, n)
#define MAXP 40000 // max primes counter
#define MAX 400010 // max prime
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))
#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define isprime(x) (((x) && ((x)&1) && (!chkbit(ar, (x)))) || ((x) == 2))

using namespace std;

long long dp[MAXN][MAXM];
unsigned int ar[(MAX >> 6) + 5] = {0};
int len = 0, primes[MAXP], counter[MAX];

void Sieve() //线性筛预处理[1,n^(2/3)]内的质数
{
    setbit(ar, 0), setbit(ar, 1);
    for (int i = 3; (i * i) < MAX; i++, i++)
    {
        if (!chkbit(ar, i))
        {
            int k = i << 1;
            for (int j = (i * i); j < MAX; j += k)
                setbit(ar, j);
        }
    }

    for (int i = 1; i < MAX; i++)
    {
        counter[i] = counter[i - 1];
        if (isprime(i))
            primes[len++] = i, counter[i]++;
    }
}

void init()
{
    Sieve();
    for (int n = 0; n < MAXN; n++)
    {
        for (int m = 0; m < MAXM; m++)
        {
            if (!n)
                dp[n][m] = m;
            else
                dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
        }
    }
}

long long phi(long long n, int m) //根据定义求phi
{
    if (m == 0)
        return n;
    if (primes[m - 1] >= n)
        return 1;
    if (n < MAXM && m < MAXN)
        return dp[m][n];
    return phi(n, m - 1) - phi(n / primes[m - 1], m - 1); //prime[]>=1,phi(m,prime[]-1)-phi(m/prime[],prime[]-1)
}

long long Lehmer(long long n)
{
    if (n < MAX)
        return counter[n];
    long long res = 0;
    int m, s, c;
    s = sqrt(0.9 + n), c = cbrt(0.9 + n);    //s:平方根 c:立方根
    m = counter[c], res = phi(n, m) + m - 1; //pi(n)=phi(n,m)-P2(n,m)+m-1,定义式变换,P2(n,m)在下一步中进行运算
    for (int i = m; primes[i] <= s; i++)
        res = res - Lehmer(n / primes[i]) + Lehmer(primes[i]) - 1; //求出P2(n,m),运算得出最终结果
    return res;
}

int main()
{
    init(); //初始化
    long long int n;
    while (scanf("%lld", &n) != EOF)
    {
        printf("%lld\n", Lehmer(n));
    }

    return 0;
}