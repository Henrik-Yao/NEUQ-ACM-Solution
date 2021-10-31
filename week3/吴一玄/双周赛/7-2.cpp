#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[10010], f[10010], ans;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        f[i] = max(f[i - 1] + a[i], f[i]);
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
}