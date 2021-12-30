#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int l = 248251329, r;
int n, m, ans = 0;
int a[N];
bool check(int x) {
    int sum = 0, base = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] - base >= x) {
            sum++; base = a[i];
        }
        if (sum >= m) return true;
    }
    if (sum + 1 < m) return false;
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; i++) l = min(l, a[i] - a[i - 1]); // 最小的左端
    r = a[n] - a[1];
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}