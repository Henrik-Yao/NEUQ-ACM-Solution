#include<bits/stdc++.h>
using namespace std;
int n,a[20];
int dfs(int index)
{
    map<int,int> m;
    int ans=0;
    for(int i=index+1;i<=n;i++)
    {
        if(a[i]>=a[index]&&m[a[i]]==0)
        {
            m[a[i]]=1;
            ans+=dfs(i)+1;
        }
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    map<int,int> m;
    for(int i=1;i<=n;i++)
    {
        if(m[a[i]]==0)
        {
            m[a[i]]=1;
            ans+=dfs(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}
