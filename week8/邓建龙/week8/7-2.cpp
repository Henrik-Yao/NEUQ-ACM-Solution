#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, q[N], k = 0, tmp = 1, save, mx;
int find(int l, int r)
{
    int ans = l + 1;
    for (int i = l; i <= r; i++) if (q[l] < q[i]) q[l] = q[i], ans = i;
    return ans;
}
int link(int l, int r)
{
    int ans = l;
    for (int i = ans; i <= r; i++) if (q[l] < q[i] + i - l) ans = l = i;
    return ans;
}
int main()
{
    scanf("%d", &n);for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    while (k + q[k] < n - 1) save = q[k], mx = find(k, q[k] + k), k = link(mx, save + k), tmp++;
//     cout << tmp << endl;
    cout << tmp;
}


