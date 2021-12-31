#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool isPrime(LL x)
{
    for (int i = 2; i <= sqrt(x); ++i)
    {
        if (!(x % i))
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    LL num;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%lld", &num);
        //        cout<<"++++"<<isPrime(num)<<endl;
        if (!(num % 2))
        {
            printf("2\n");
        }
        else if (isPrime(num))
        {
            printf("1\n");
        }
        else if (isPrime(num - 2))
        {
            printf("2\n");
        }
        else
        {
            printf("3\n");
        }
    }
    return 0;
}