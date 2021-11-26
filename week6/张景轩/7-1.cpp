#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAX = 1000010;
const ull base = 131;

int n;
ull h[MAX], Pow[MAX];
char s[MAX], t[MAX];

int main()
{
    cin>>s + 1;
    n = strlen(s + 1);
    for(int i = 1; i <= n; ++i)
    {
        h[i] = h[i - 1] * base + (ull)s[i];
    }
    Pow[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        Pow[i] = Pow[i - 1] * base;
    }
    cin>>t + 1;
    int m = strlen(t + 1);
    ull ht = 0; int ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        ht = ht * base + (ull)t[i];
    }
    for(int i = 1; i + m - 1 <= n; ++i)
    {
        ll hs = h[i + m - 1] - h[i - 1] * Pow[m];
        if(hs == ht) ++ans;
    }
    cout<<ans;
    return 0;
}