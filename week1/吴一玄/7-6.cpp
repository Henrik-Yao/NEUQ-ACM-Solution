#include<bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    scanf("%d %d", &n, &m);
    int ans = -0x7fffffff;
    for(int i = 1; i <= n; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        if(y <= m) ans = max(ans, x);
        else ans = max(ans, x - (y - m));
    }
    printf("%d\n", ans);
    return 0;
}