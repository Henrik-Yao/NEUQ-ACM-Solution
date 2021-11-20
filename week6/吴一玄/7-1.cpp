#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1000010;
const ull Base = 131;

int n; ull h[MAXN], Pow[MAXN];
char s[MAXN], t[MAXN];

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i = 1; i <= n; ++i) h[i] = h[i - 1] * Base + (ull)s[i];
    Pow[0] = 1; for(int i = 1; i <= n; ++i) Pow[i] = Pow[i - 1] * Base;
    scanf("%s", t + 1);
    int m = strlen(t + 1);
    ull ht = 0; int ans = 0;
    for(int i = 1; i <= m; ++i) ht = ht * Base + (ull)t[i];
    for(int i = 1; i + m - 1 <= n; ++i)
    {
        ll hs = h[i + m - 1] - h[i - 1] * Pow[m];
        if(hs == ht) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}