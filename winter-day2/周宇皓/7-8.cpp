#include<bits/stdc++.h>
using namespace std;
int a[200009],t,n,ans=0;
bool flag;
void zhong(int num,int shen)
{
    if(a[num]==0) return;
    ans=max(ans,shen);
    zhong(num*2,shen+1);
    if(flag==0)
    {
        cout<<a[num];
        flag=1;
    }
    else 
        cout<<' '<<a[num];
    zhong(num*2+1,shen+1);
}
int main()
{
    cin>>t;
    while (t--)
    {
        flag=0;
        memset(a,0,sizeof a);
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        zhong(1,1);
        cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}
