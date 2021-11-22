#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int t;
int q[N], f[N];
int main()
{
    cin >> t;
    int m = t;
    while (m--)
    {
        if (m != t - 1) cout << endl;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) scanf("%d", &q[i]), f[i] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (q[j] < q[i]) f[i] = max(f[i], f[j] + 1);
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
        cout << ans << endl;
    }
    return 0;
}