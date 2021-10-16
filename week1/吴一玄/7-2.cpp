#include<bits/stdc++.h>
using namespace std;

int n, a[1000010];
int cnt1[100010], cnt2[100010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int res1 = 0, res2 = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!cnt2[a[i]]) ++res2;
        cnt2[a[i]]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(!cnt1[a[i]]) ++res1;
        cnt1[a[i]]++;
        --cnt2[a[i]];
        if(!cnt2[a[i]]) --res2;
        ans = max(ans, res1 + res2);
    }
    cout << ans << "\n";
    return 0;
}