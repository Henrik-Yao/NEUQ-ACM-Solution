#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int n, m;
int f[N];
int v[N], w[N];
int main()
{
    while (cin >> n >> m)
    {
        memset(v, 0, sizeof v), memset(w, 0, sizeof w), memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) cin >> v[i];
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= v[i]; j--) f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
        cout << f[m] << endl;
    }
    return 0;
}