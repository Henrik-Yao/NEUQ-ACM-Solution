#include <iostream>
using namespace std;
long long sum = 0;
void guibing(long long a[], long long s, long long m, long long e, long long cache[])
{
    long long p = 0;
    long long i = s, j = m + 1;
    while (i <= m && j <= e)
    {
        if (a[i] > a[j])
        {
            sum += e - j + 1;
            cache[p++] = a[i++];
        }
        else
        {
            cache[p++] = a[j++];
        }
    }
    while (i <= m)
    {
        cache[p++] = a[i++];
    }
    while (j <= e)
    {
        cache[p++] = a[j++];
    }
    for (long long i = 0; i < e - s + 1; i++)
    {
        a[s + i] = cache[i];
    }
}
void fenzhipaixu(long long a[], long long s, long long e, long long cache[])
{
    if (s < e)
    {
        long long m = s + (e - s) / 2;
        fenzhipaixu(a, s, m, cache);
        fenzhipaixu(a, m + 1, e, cache);
        guibing(a, s, m, e, cache);
    }
}
long long cache[1000009];
main()
{
    long long n;
    cin >> n;
    long long a[n+10];
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    fenzhipaixu(a, 0, n - 1, cache);
    cout << sum;
}
