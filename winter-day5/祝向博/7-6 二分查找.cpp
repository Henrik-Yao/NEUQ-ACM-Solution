#include <bits/stdc++.h>
using namespace std;
int N, M, a[1005];
int main() {
#ifndef ONLINE_JUDGE
    freopen("prob.in", "r", stdin);
#endif
    while (~scanf("%d", &N)) {
        for (int i = 1; i <= N; ++i) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + N);
        for (int i = 1; i < N; ++i) cout << a[i] << " ";
        cout << a[N] << endl;
        scanf("%d", &M);
        for (int i = 1; i <= M; ++i) {
            int x;
            scanf("%d", &x);
            auto p = lower_bound(a+1, a+1+N, x);
            int P = p - a;
            if (a[P] == x) cout << P;
            else cout << "0";
            if (i < M) cout << " "; else cout << endl;
        }
    }
    return 0;
}
