#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;
struct edge
{
    int f,t;
    int v;
};
edge a[90005];
int compare(edge x,edge y)
{
    return x.v<y.v;
}
int pre[305];
int find(int x)
{
    if(x!=pre[x])
    {
        pre[x]=find(pre[x]);
    } 
    return pre[x];
}
int main()
{
    int i,j,n,m,max,ans;
    int d1,d2;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            pre[i]=i;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&a[i].f,&a[i].t,&a[i].v);
        }

        sort(a,a+m,compare);
        ans=0;
        max=0;

        for(i=0;i<m;i++)
        {
            d1=find(a[i].f);
            d2=find(a[i].t);
            if(d1!=d2)
            {
                pre[d1]=d2;
                ans++;
                if(ans>n-1)
                {
                    break;
                }
                if(max<a[i].v)
                {
                    max=a[i].v;
                }
            }
        }
        cout<<n-1<<" "<<max;
    }
    return 0;
}