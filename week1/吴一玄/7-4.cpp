#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll f[1010];

ll dp(int n)
{
    if(!n) return 1;
    if(f[n] != -1) return f[n];
    ll ans = 1;
    for(int i = 1; i < n; ++i)
        if(n % i == 0) ans += dp(i);
    return f[n] = ans;
}

int main()
{
    memset(f, -1, sizeof(f));
    int n; cin >> n;
    cout << dp(n) << endl;
    return 0;
}