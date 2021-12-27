#include<bits/stdc++.h>
using namespace std;
int edge[10010],nxt[10010],head[100010],tot=0,root,f1ag=0,t1;
int f[1000][1000],d[10000];
int sum=1,t;
void add(int x,int y)
{
	++tot;
	edge[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void creat(int r)
{
	int x;
	while(cin>>x)
	{
		if(f1ag==0)
		{
			root=x;
			r=root;
			f1ag=1;
		}
		if(x!=0)
		{
			sum++;
			add(r,x);
			add(x,r);
		}
		else
		{
			return ;
		}
		creat(x);
	}
	return;	
}
void bfs(int s)
{
	queue<int> q;
    q.push(s);
    d[s]=1;
    while(q.size())
    {
        int x=q.front();q.pop();
        for(int i=head[x];i;i=nxt[i])
        {
            int y=edge[i];
            if(d[y])
                continue;
            d[y]=d[x]+1;
            f[y][0]=x;
            for(int j=1;j<=t1;j++)
                f[y][j]=f[f[y][j-1]][j-1];
            q.push(y);
        }
    }
}
int lca(int x,int y)
{
    if(d[x]>d[y])
        swap(x,y);
    for(int i=t1;i>=0;i--)
        if(d[f[y][i]]>=d[x])
            y=f[y][i];
    if(x==y)
        return x;
    for(int i=t1;i>=0;i--)
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i],y=f[y][i];
        }
    return f[y][0];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		sum=0;
		f1ag=0;
		memset(edge,0,sizeof(edge));
		memset(head,0,sizeof(head));
		memset(nxt,0,sizeof(nxt));
		memset(f,0,sizeof(f));
		memset(d,0,sizeof(d));
		creat(0);
//		cout<<sum<<" "<<endl;
		t1=log2(sum)+2;
		bfs(root);
		int x1,y1;
		cin>>x1>>y1;
		cout<<lca(y1,x1)<<endl;
	}
}
