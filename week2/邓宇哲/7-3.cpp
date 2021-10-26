#include <iostream>
using namespace std;
void guibing(long long a[], long s, long m, long e, long long cache[])
{
    long initial = 0;
    long point1 = s, point2 = m + 1;
    while (point1 <= m && point2 <= e)
    {
        if (a[point1] < a[point2])
        {
            cache[initial++] = a[point1++];
        }
        else
        {
            cache[initial++] = a[point2++];
        }
    }
    while (point1 <= m)
    {
        cache[initial++] = a[point1++];
    }
    while (point2 <= e)
    {
        cache[initial++] = a[point2++];
    }
    for (int i = 0; i < e - s + 1; i++)
    {
        a[s + i] = cache[i];
    }
}
void paixu(long long a[], long s, long e, long long cache[])
{
    if (s < e)
    {
        int m = s + (e - s) / 2;
        paixu(a, s, m, cache);
        paixu(a, m + 1, e, cache);
        guibing(a, s, m, e, cache);
    }
}
long long cache[100000];
main()
{
    long n;
    cin >> n;
    long long a[n];
    for (long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    paixu(a, 0, n - 1, cache);
    for (long i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }
}
