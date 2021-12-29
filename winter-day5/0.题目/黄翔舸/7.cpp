#include <iostream>
#include<algorithm>
using namespace std;
int a[100010];
int l, r;
int n, c;


bool juge(int m)
{
    int ans = 1, last = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] - a[last] >= m)
        {
            ans++;
            last = i;
        }
    }
    if (ans >= c)
        return true;
    return false;
}

int main()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)cin >> a[i];
    l = 1; r = a[n] - a[1];
    sort(a + 1, a + 1 + n);
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (juge(mid))l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r << endl;
    return 0;
}