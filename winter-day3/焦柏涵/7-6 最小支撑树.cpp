#include <bits/stdc++.h>
using namespace std;
#define maxn 100000
struct st{
	int a,b,c;
	bool operator < (const st&x) const{
		return c<x.c;
	}//жиди< 
} road[maxn];
int lk[maxn];
int find(int d)
{
	if(d!=lk[d]) lk[d]=find(lk[d]);
	return lk[d];
}
void match(int p,int q)
{
	lk[find(p)]=find(q);
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++) lk[i]=i;
		for(int i=1;i<=m;i++) cin>>road[i].a>>road[i].b>>road[i].c;
		sort(road+1,road+1+m);
		int num=0,maxa=0;
		for(int i=1;i<=m;i++)
		{
			if(find(road[i].a)!=find(road[i].b))
			{
				match(road[i].a,road[i].b);
				maxa+=road[i].c;
				num++;
				if(num==n-1) break;
			}
		}
		if(num!=n-1) cout<<"There is no minimum spanning tree."<<endl;
		else cout<<maxa<<endl;
	}
	
	return 0;
}
