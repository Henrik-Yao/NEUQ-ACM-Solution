#include <bits/stdc++.h>
using namespace std;
int cmp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, lns;
    cin >> N >> lns;
    int a[N];
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i];
    }
    qsort(a, N, sizeof(int), cmp);
    int d[N - 1];
    for (int i = 0; i < N - 1; ++i)
    {
        d[i] = a[i] - a[i + 1] - 1;
    }
    qsort(d, N - 1, sizeof(int), cmp);
    int len = a[0] - a[N - 1] + 1;
    for (int i = 0; i < lns - 1; ++i)
    {
        len = len - d[i];
    }
    cout << len;
    return 0;
}