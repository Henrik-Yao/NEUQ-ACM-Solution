#include <bits/stdc++.h>
using namespace std;
long long hanoi3(long long x);
int main()
{
    long long n;
    while (scanf("%lld", &n) != EOF)
    {
        cout << hanoi3(n) << endl;
    }
    return 0;
}
long long hanoi3(long long x)
{
    long long re;
    if (x == 1)
    {
        re = 2;
    }
    else
    {
        re = 3 * hanoi3(x - 1) + 2;
    }
    return re;
}
