#include <bits/stdc++.h>
using namespace std;
//#define ll long long
#define lowbit(i) ((i)&(-i))
long long a[1000005];
int n,q;
long long getsss(int x)
{
    long long s=0;
    for(int i=x;i>0;i=i-lowbit(i))
    s+=a[i];
    return s;
}
void add(int x,int y)
{
    for(int i=x;i<=n;i=i+lowbit(i))
    a[i]+=y;
}
int  main()
{
    
    cin>>n>>q;
    //ll a[n+1];
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
    {
        int ans;cin>>ans;
        add(i,ans);
    }
    
    while(q--)
    {
        int f,x,y;
        cin>>f>>x>>y;
        if(f==1)
        {
            add(x,y);
        }
        if(f==2)
        {
            cout<<getsss(y)-getsss(x-1)<<endl;
        }
    }
    return 0;
}