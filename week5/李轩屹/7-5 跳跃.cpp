#include<iostream>
#include<queue>
using namespace std;
const int maxn=5e4+10;
int a[maxn],n,fa[maxn];
bool vis[maxn];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y){ fa[find(x)]=find(y);}
int bfs(int x)
{
	queue<int>q;
	q.push(x);
	while(!q.empty())
	{
		int t=q.front();
		q.pop();
		if(a[t]==0) return 1;
		if(vis[t]) continue;
		vis[t]=1;
		if(t+a[t]<=n) q.push(t+a[t]);
		if(t-a[t]>0) q.push(t-a[t]);
	}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		fa[i]=i;
	}
	int s;
	cin>>s;
	s++;
	if(bfs(s)) cout<<"True";
	else cout<<"False";
}




