#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long M=200005;
typedef struct lx
{
	ll nx,to,sp;
};
lx lx1[M],lx2[M];
ll n,m,q,tot1=0,tot2=0,head1[M],head2[M];
ll xjin[M],djin[M];
bool vis[M];
multiset<ll> mincost;
void add1(ll h,ll to,ll sp)
{
	lx1[++tot1].to=to;
	lx1[tot1].sp=sp;
	lx1[tot1].nx=head1[h];
	head1[h]=tot1;
}
void add2(ll h,ll to,ll sp)
{
	lx2[++tot2].to=to;
	lx2[tot2].sp=sp;
	lx2[tot2].nx=head2[h];
	head2[h]=tot2;
}
void DIJ1(ll s)
{
	queue<ll>q;
	fill(xjin,xjin+M,LLONG_MAX);
	fill(vis,vis+M,0);
	xjin[s]=0;
	q.push(s);
	while(!q.empty())
	{
		ll x=q.front();
		q.pop();
		if(vis[x]){continue;}
		vis[x]=1;
		for(ll i=head1[x];i;i=lx1[i].nx)
		{
			ll to=lx1[i].to;
			ll sp=lx1[i].sp;
			if(xjin[to]>xjin[x]+sp)
			{
				xjin[to]=xjin[x]+sp;
				q.push(to);
			}
		}
	}	
}
void DIJ2(ll s)
{
	queue<ll>q;
	fill(djin,djin+M,LLONG_MAX);
	fill(vis,vis+M,0);
	djin[s]=0;
	q.push(s);
	while(!q.empty())
	{
		ll x=q.front();
        q.pop();
		if(vis[x]){continue;}
		vis[x]=1;
		for(ll i=head2[x];i;i=lx2[i].nx)
		{
			ll to=lx2[i].to;
			ll sp=lx2[i].sp;
			if(djin[to]>djin[x]+sp)
			{
				djin[to]=djin[x]+sp;
				q.push(to);
			}
		}
	}
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&q);
	for(ll i=1;i<=m;i++)
	{
		ll x,y,z,d;
		scanf("%lld%lld%lld%lld",&x,&y,&z,&d);
		if(x==y){continue;}
		add1(x,y,z);
		add2(y,x,d);
	}
	DIJ1(1);
	DIJ2(n);
	ll st[M],jin[M];
	for(ll i=1;i<=n;i++){scanf("%lld",&st[i]);}
	for(ll i=1;i<=n;i++)
	{
		if(xjin[i]>=LLONG_MAX-10||djin[i]>LLONG_MAX-10){continue;}
		jin[i]=xjin[i]+(djin[i]+st[i]-1)/st[i];
		mincost.insert(jin[i]);
	}
	for(ll i=1;i<=q;i++)
	{
		ll num,b;
		scanf("%lld%lld",&num,&b);
		if(!jin[num]||st[num]==b)
		{
				cout<<*mincost.begin()<<endl;
		}
		else
		{
			mincost.erase(mincost.find(jin[num]));
			st[num]=b;
			mincost.insert(jin[num]=xjin[num]+(djin[num]+st[num]-1)/st[num]);
				cout<<*mincost.begin()<<endl;
		}
	}
	return 0;
}
