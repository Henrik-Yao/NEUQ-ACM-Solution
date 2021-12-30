#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int biosearch(int x, int l, int r, int a[])
{
    if (l > r)
    {
        return -1;
    }
    int mid = (l + r) / 2;
    if (x == a[mid])
    {
        cnt++;
        return mid;
    }
    else if (x < a[mid])
    {
        cnt++;
        return biosearch(x, l, mid - 1, a);
    }
    else
    {
        cnt++;
        return biosearch(x, mid + 1, r, a);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int re = biosearch(x, 0, n - 1, a);
    if (re == -1)
    {
        cout << -1 << endl
             << cnt << endl;
    }
    else
    {
        cout << re << endl
             << cnt << endl;
    }
    return 0;
}