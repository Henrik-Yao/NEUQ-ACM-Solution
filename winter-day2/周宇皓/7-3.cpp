#include<bits/stdc++.h>
using namespace std;
const int N=500009;
int t,x,root=0,n1,n2,ans,a,b;
map<int,vector<int>> m;
map<int,int> mm;
int find(int x)
{
    if(x!=mm[x]) mm[x]=find(mm[x]);
    return mm[x];
}
void dfs(int level,int las)
{
    cin>>x;
    mm[x]=x;
    if(root==0) root=x;
    if(level==1) dfs(2,x);
    else 
    {
        vector<int> v;
        if(x==0) return ;
        else 
        {
            v.push_back(x);
            dfs(level+1,x);
        }
        while(cin>>x)
        {
            if(x==0) 
            {
                m[las]=v;
                return ;
            }
            else 
            {
                mm[x]=x;
                v.push_back(x);
                dfs(level+1,x);
            }
        }
    }
}
void df(int now)
{
    for(int i=0;i<m[now].size();i++)
    {
        int j=m[now][i];
        df(j);
        mm[j]=now;
        if(find(a)==find(b)&&ans==0) ans=now;
    }
}
int main()
{
    cin>>t;
    while(t--)
    {
        root=0;
        m.clear();
        mm.clear();
        dfs(1,-1);
        ans=0;
        n1=n2=0;
        cin>>a;
        cin>>a>>b;
        df(root);
        cout<<ans<<endl;
    }
    return 0;
}
