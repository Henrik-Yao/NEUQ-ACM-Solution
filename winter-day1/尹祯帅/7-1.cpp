#include <bits/stdc++.h>
using namespace std;
#define lowbit(i) (i&(-i))
long long c[1000002],n;
void update(int i,int x)
{
    for(;i<=n;i+=lowbit(i)) c[i]+=x;
}
long long add(int l)
{
    long long sum=0;
    for(;l>0;l-=lowbit(l)) sum+=c[l];
    return sum;
}
int main()
{
    int q;
    cin>>n>>q;
    memset(c,0,n);
    int a;
    for(int i=1;i<=n;i++) 
    {
        cin>>a;
        update(i,a);
    }
    int jud,x,y;
    while(q--)
    {
        cin>>jud>>x>>y;
        if(jud==1) update(x,y);
        else if(jud==2) cout<<add(y)-add(x-1)<<'\n';
    }
    return 0;
}
