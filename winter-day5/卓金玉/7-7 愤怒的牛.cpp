#include <bits/stdc++.h>
using namespace std;
int n, m;
#define N 100005
int a[N];
bool quest(int mid)
{
    int cnt = 1;
    int pos = a[0] + mid;
    for (int i = 0; i < n; ++i)
    {
        if (pos <= a[i])
        {
            cnt++;
            pos = a[i] + mid;
        }
    }
    return m <= cnt ? 1 : 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int mid = 0, l = 0, r = a[n - 1] - a[0];
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (quest(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l - 1;
    return 0;
}
