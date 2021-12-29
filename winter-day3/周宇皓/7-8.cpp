#include<bits/stdc++.h>
using namespace std;
const int N=1009;
int n,m,head[N],cnt,indgr[N],cop[N];
struct Edge
{
    int to,nex;
}edge[N];
void add(int a,int b)
{
    edge[++cnt].to=b;
    edge[cnt].nex=head[a];
    head[a]=cnt;
}
bool topsort()
{
    queue<int> q;
    int num=0;
    for(int i=1;i<=n;i++) 
    if(indgr[i]==0) q.push(i);
    while (!q.empty())
    {
        int a=q.front();
        q.pop();
        num++;
        for(int i=head[a];i!=-1;i=edge[i].nex)
        {
            int j=edge[i].to;
            indgr[j]--;
            if(indgr[j]==0) q.push(j);
        }
    }
    return num==n;
}
bool check()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    if(cop[i]==0) q.push(i);
    if(q.size()!=1) return false;
    while (!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int i=head[a];i!=-1;i=edge[i].nex)
        {
            int j=edge[i].to;
            cop[j]--;
            if(cop[j]==0) q.push(j);
        }
        if(q.size()>1) return false;
    }    
    return true;
}
int main()
{
    while(cin>>n>>m)
    {
        memset(indgr,0,sizeof indgr);
        memset(head,-1,sizeof head);
        cnt=0;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            add(a,b);
            indgr[b]++;
        }
        for(int i=1;i<=n;i++) cop[i]=indgr[i];
        if(topsort())
        {
            if(check()) cout<<1<<endl;
            else cout<<2<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}
