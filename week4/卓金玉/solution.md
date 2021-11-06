# WEEK4 周报
## 7-1 素数
### 题面

编写一个程序，求出【a,b】范围内的素数。

**输入格式:**
输入数据有多组，每组占一行,输入两个数a,b。(整型范围内)

**输出格式:**
输出【a,b】区间内的素数，空格隔开。（2<=a,b<=10000）

**输入样例:**
在这里给出一组输入。例如：
```
5 10
3 15
结尾无空行
```
**输出样例:**

```
5 7
3 5 7 11 13
结尾无空行
```
### 思路
这个暴力筛可解，但是有个笨比PE了好多次，我不说是谁

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
int prime(int m);
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n, m;
    while (cin >> n >> m)
    {
        int f = 0;
        for (int i = n; i <= m; ++i)
            if (prime(i) && !f)
            {
                cout << i;
                f++;
            }
            else if (prime(i))
                cout << " " << i;
        cout << endl;
    }
    return 0;
}
int prime(int m)
{
    int flag = 1, i;
    if (m == 0 || m == 1)
        flag = 0;
    for (i = 2; i <= sqrt(m); i++)
    {
        if (!(m % i))
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
```

## 7-2 炒鸡楼梯
### 题面
你知道吗？有一种编程题需要自己推导公式，得出公式一下子就能解决问题。

具体步骤就是自己先按顺序推算几个比较小的情况，看看这几个之间有没有规律，找到规律你就能解决问题了。试着解决下面这个问题吧。

有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级，要走上第M级，共有多少种走法？
**输入格式:**
输入数据首先包含一个整数N，表示测试实例的个数，然后是N行数据，每行包含一个整数M（1<=M<=40）,表示楼梯的级数。

**输出格式:**
对于每个测试实例，请输出不同走法的数量

**输入样例:**
```
2
2
3
结尾无空行
```
**输出样例:**
```
1
2
结尾无空行
```

### 思路
找规律列递推式子可解

### 代码
```c++
#include <bits/stdc++.h>
using namespace std;
long long a[41];
int main()
{
    a[1] = 0;
    a[2] = 1;
    a[3] = 2;
    for (int i = 4; i < 41; ++i)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    int T, n;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i)
    {
        scanf("%d", &n);
        printf("%d\n", a[n]);
    }
    return 0;
}
```

## 7-3 求素数个数
### 题面
求素数的个数。本题要求编写一个程序，求1~n的素数个数。 要求至少给出两种解法，对于相同的n，给出这两种解法的结果，通过相关数据进行测试，目的是通过对比同一问题不同解法的绝对执行时间体会如何设计“好”的算法。

**输入格式:**
输入在一行中给出1个整数n(<= 10 000 000)。

**输出格式:**
对每一组输入，在一行中输出1~n的素数个数。

**输入样例:**
```
5 
14
结尾无空行
```
**输出样例:**
```
3
6
结尾无空行
```

### 思路
发现了一个奇妙的算法(Meissel Lehmer算法)，数据大的时候很快能跑出结果，但是这个题的数据用不到这个算法(..)，算法的思路是先用普通欧拉筛预处理[1,n^(2/3)]范围内的素数，然后用定义求Π(x)(结果)
是很罕见的算法，一般情况好似也用不到~~奇怪的算法知识增加了~~
附上一些带佬的解析
[Meissel-Lehmer算法解析](https://tanakarino.cn/2020/06/02/Meissel-Lehmer%E7%AE%97%E6%B3%95/)

[Meissel-Lehmer算法，亚线性时间找出素数个数](https://www.cnblogs.com/RioTian/p/14682900.html)

[具体实现](https://blog.csdn.net/q435201823/article/details/77915852?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522163603086016780264070082%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=163603086016780264070082&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduend~default-2-77915852.first_rank_v2_pc_rank_v29&utm_term=MEISSEL-LEHMER&spm=1018.2226.3001.4187)

### 代码
```c++
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
```
## 7-4 幂次取余
### 题面

给定三个正整数A，B和C，求A^Bmod C的结果，其中mod表示求余数。

**输入格式:**
首先输入一个正整数T，表示测试数据的组数，然后是T组测试数据。每组测试数据输入三个正整数A，B，C（A，B，C≤1000000）。

**输出格式:**
对于每组测试，输出计算后的结果，每组测试的输出占一行。

**输入样例:**
```
2
3 3 5
4 4 6
结尾无空行
```
**输出样例:**
```
2
4
结尾无空行
```
### 思路
快速幂可解

### 代码
```c++
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
```
