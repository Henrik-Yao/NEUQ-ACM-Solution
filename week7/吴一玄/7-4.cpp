#include<bits/stdc++.h>
using namespace std;

int f[1010], a[1010];

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        int n; scanf("%d", &n);
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        int ans = 1; a[0] = -1;
        for(int i = 1; i <= n; ++i)
        {
            f[i] = 0;
            for(int j = 0; j < i; ++j)
                if(a[i] > a[j]) f[i] = max(f[i], f[j] + 1);
            ans = max(ans, f[i]);
        }
        printf("%d\n", ans);
        if(T) puts("");
    }
    return 0;
}