#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1100010;
const ull Base = 131;

int n; ll pre[MAXN], suf[MAXN];
char s[MAXN]; ll cnt[26], sum[26];
ull Hash[MAXN], Pow[MAXN];

int main()
{
    Pow[0] = 1ull; for(register int i = 1; i < MAXN; ++i) Pow[i] = Pow[i - 1] * Base;
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%s", s + 1);
        n = strlen(s + 1);
        memset(cnt, 0, sizeof(cnt));
        for(register int i = 1; i <= n; ++i)
        {
            cnt[s[i] - 'a']++;
            int res = 0;
            for(register int j = 0; j < 26; ++j) if(cnt[j] & 1) ++res;
            pre[i] = res;
        }
        memset(cnt, 0, sizeof(cnt));
        for(register int i = n; i; --i)
        {
            cnt[s[i] - 'a']++;
            int res = 0;
            for(register int j = 0; j < 26; ++j) if(cnt[j] & 1) ++res;
            suf[i] = res;
        }
        for(register int i = 1; i <= n; ++i) Hash[i] = Hash[i - 1] * Base + (ull)s[i];
        ll ans = 0; memset(cnt, 0, sizeof(cnt));
        cnt[pre[1]]++; sum[0] = cnt[0];
        for(register int j = 1; j < 26; ++j) sum[j] = sum[j - 1] + cnt[j];
        for(register int i = 2; i < n; ++i)
        {
            ull now = 0, H = Hash[i];
            for(register int j = i; j < n; j += i)
            {
                now = now * Pow[i] + H;
                if(now != Hash[j]) break;
                int fc = suf[j + 1];
                ans += sum[fc];
            }
            cnt[pre[i]]++; sum[0] = cnt[0];
            for(register int j = 1; j < 26; ++j) sum[j] = sum[j - 1] + cnt[j];
        }
        printf("%lld\n", ans);
    }
    return 0;
}