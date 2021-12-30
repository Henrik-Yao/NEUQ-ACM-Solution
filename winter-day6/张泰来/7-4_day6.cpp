#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int n;
int a[500005];
int c[500005];
int dx[500005];
long long ans = 0;
int lowbits(int x)
{
    return x & ( - x);
}
void add(int x)
{
    for (;x <= n;x += lowbits(x))
    ++c[x];
}
int getsum(int x)
{
    int ans = 0;
    for (;x; x -= lowbits(x))
    ans += c[x];
    return ans;
}
int main()
{
    scanf("%d",&n);
    for (int i = 1;i <= n; i++)	
    {
        scanf("%d",a + i);
        dx[i] = a[i];
    }
    sort(dx + 1, dx + n + 1);
    for (int i = 1;i <= n; i++)
    {
        int pos = lower_bound(dx + 1,dx + n + 1,a[i]) - dx;
        a[i] = pos;
    }
    for (int i = 1;i <= n; i++)
    {
        add(a[i]);
        ans += i - getsum(a[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
