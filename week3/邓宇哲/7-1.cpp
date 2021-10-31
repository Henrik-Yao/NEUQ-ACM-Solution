#include <iostream>
using namespace std;
int zdh( int a[], int, int);
main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << zdh(a, 0, n - 1);
}
int zdh( int a[], int s, int e)
{
    if (s == e)
    {
        return a[s];
    }
    int m = (e + s) / 2;
    int sum1 = zdh(a, s, m);
    int sum2 = zdh(a, m+1 , e);
    int cache = 0, lmax = 0, rmax = 0;
    for (int i = m; i >= s; i--)
    {
        cache += a[i];
        lmax = max(lmax, cache);
    }
    cache = 0;
    for (int i = m+1; i <= e; i++)
    {
        cache += a[i];
        rmax = max(rmax, cache);
    }
    int sum3 = lmax + rmax;
    return max(max(sum1, sum3),sum2);
}
