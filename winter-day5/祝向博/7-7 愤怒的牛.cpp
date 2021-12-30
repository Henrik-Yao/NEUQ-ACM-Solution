#include <bits/stdc++.h>
using namespace std;
int N, M, a[100005];

bool check(int x) {
    int t = 1, k = 1;
    for (int i = 2; i <= N; ++i) {
        if (a[i] - a[t] >= x) t = i, ++k;
        if (k >= M) return 1;
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("prob.in", "r", stdin);
#endif
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) cin >> a[i];
    sort(a + 1, a + 1 + N);
    int L = 0, R = a[N] - a[1];
    while (L <= R) {
        int mid = (L + R) / 2;
        if (!check(mid)) R = mid - 1;
        else L = mid + 1;
    }
    cout << L - 1;
    return 0;
}
