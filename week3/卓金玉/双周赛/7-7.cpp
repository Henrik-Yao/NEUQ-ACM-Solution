#include <bits/stdc++.h>
#define N 1000001
long long a[N], b[N];
long long find(long long a[], long long b[], long long first, long long last)
{
    long long i, j, k = 0, mid;
    long long num = 0;
    if (first >= last)
    {
        return 0;
    }
    mid = (first + last) / 2;
    k = i = first;
    j = mid + 1;
    num = find(a, b, i, mid) + find(a, b, j, last);
    while ((i <= mid) && (j <= last))
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
            num += j - mid - 1;
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while (i <= mid)
    {
        b[k++] = a[i++];
        num += j - mid - 1;
    }
    while (j <= last)
    {
        b[k++] = a[j++];
    }
    for (i = first; i <= last; ++i)
    {
        a[i] = b[i];
    }
    return num;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    for (long long i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }
    long long re = find(a, b, 0, n - 1);
    printf("%lld", re);

    return 0;
}
