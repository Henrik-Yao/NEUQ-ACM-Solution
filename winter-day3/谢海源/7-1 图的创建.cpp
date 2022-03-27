#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
//邻接表创建图
struct edge
{
	int from,to,w;
	edge(int a,int b,int c)
	{
		from=a;to=b;w=c;
	}
};
vector<edge>ed[maxn];
bool cmp(edge &a,edge &b)
{
	return a.to<b.to;
}
int main()
{
	int n,e;
	cin>>n>>e;
	int a,b,c;
	for(int i=0;i<n;i++) ed[i].clear();
	
	for(int i=0;i<e;i++)//e行
	{
		scanf("%d %d %d",&a,&b,&c);
		ed[a].push_back(edge(a,b,c));
	}
	for(int i=0;i<n;i++)//顶点
	{	
	    if(ed[i].empty()) continue;
		cout<<i<<":";
		sort(ed[i].begin(),ed[i].end(),cmp);
		for(auto &k:ed[i])
		{
			printf("(%d,%d,%d)",k.from,k.to,k.w);
		}
		cout<<endl;
	}
    return 0;
}
