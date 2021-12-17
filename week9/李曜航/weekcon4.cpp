#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
bool cmp(int a, int b)
{
    return a>b;
}
int main()
{
    int a[100000] = {0};
    int dist[100000] = {0};
    // freopen("read.in","r",stdin);
    int n = read(), m = read();
    for(int i=1;i<=n;i++)
        a[i] = read();
    sort(a+1,a+1+n);
    for(int i=1;i<n;i++)
        dist[i] = a[i+1] - a[i] - 1;
    sort(dist+1,dist+n,cmp);
    // for(int i=1;i<n;i++)
        // cout<<dist[i]<<" ";
    int ans = n;
    for(int i=m;i<n;i++)
        ans+=dist[i];
    cout<<ans;
    return 0;

}