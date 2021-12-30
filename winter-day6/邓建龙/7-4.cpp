#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 6e5 + 10;
LL n, ans = 0;
int q[N], tmp[N];
LL merge_sort(int l, int r)
{
    if (l >= r) return 0;
    int mid = l + r >> 1;
    ans = merge_sort(l, mid) + merge_sort(mid + 1, r);
    int idx = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) q[i] <= q[j] ? tmp[idx++] = q[i++] : (tmp[idx++] = q[j++], ans += mid - i + 1);
    while (i <= mid) tmp[idx++] = q[i++];
    while (j <= r) tmp[idx++] = q[j++];
    for (int u = l, v = 0; u <= r; u++, v++) q[u] = tmp[v];
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    printf("%lld", merge_sort(0, n - 1));
    return 0;
}