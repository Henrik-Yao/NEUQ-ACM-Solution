#include<bits/stdc++.h>
using namespace std;

int f[2010], w[2010], v[2010];

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        memset(f, 0, sizeof(f));
        for(int i = 1; i <= n; ++i) scanf("%d", &w[i]);
        for(int i = 1; i <= n; ++i) scanf("%d", &v[i]);
        for(int i = 1; i <= n; ++i)
            for(int j = m; j >= w[i]; --j)
                f[j] = max(f[j], f[j - w[i]] + v[i]);
        printf("%d\n", f[m]);
    }
    return 0;
}