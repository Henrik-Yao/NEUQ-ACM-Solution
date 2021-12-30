#include <set>
#include <queue>
#include <climits>
#include <cstdio>
#define N 100001
#define ll long long
#define inf LLONG_MAX
using namespace std;

int n,m,q,u1[N],u2[N],a[N];
ll dis1[N],dis2[N],con[N],rate[N];
multiset<ll> ans;

int p1,head1[N],p2,head2[N];
struct ss{
	int to;
	ll c;
	int ls;
	bool operator < (const ss &r)const{return r.c < c;}
}q1[N * 2],q2[N * 2];

void add1(int a , int b , int c){q1[++ p1] = (ss){b , (ll)c , head1[a]};head1[a] = p1;}
void add2(int a , int b , int c){q2[++ p2] = (ss){b , (ll)c , head2[a]};head2[a] = p2;}

void dijkstra1(){
	for(int i = 2;i <= n;i ++)
		dis1[i] = inf;
	priority_queue<ss> q;
	q.push((ss){1 , 0});
	while(!q.empty()){
		ss now = q.top();
		q.pop();
		int x = now.to;
		if(u1[x]) continue;
		u1[x] = 1;
		for(int i = head1[x];i;i = q1[i].ls){
			int to = q1[i].to;
			ll c = q1[i].c;
			if(!u1[to] && dis1[to] > dis1[x] + c){
				dis1[to] = dis1[x] + c;
				q.push((ss){to , dis1[to]});
			}
		}
	}
}

void dijkstra2(){
	for(int i = 1;i < n;i ++)
		dis2[i] = inf;
	priority_queue<ss> q;
	q.push((ss){n , 0});
	while(!q.empty()){
		ss now = q.top();
		q.pop();
		int x = now.to;
		if(u2[x]) continue;
		u2[x] = 1;
		for(int i = head2[x];i;i = q2[i].ls){
			int to = q2[i].to;
			ll c = q2[i].c;
			if(!u2[to] && dis2[to] > dis2[x] + c){
				dis2[to] = dis2[x] + c;
				q.push((ss){to , dis2[to]});
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i <= m;i ++){
		int u,v,c,d;
		scanf("%d%d%d%d",&u,&v,&c,&d);
		add1(u , v , c);
		add2(v , u , d);
	}
	dijkstra1();
	dijkstra2();
	for(int i = 1;i <= n;i ++)
		scanf("%d",&rate[i]);
	for(int i = 1;i <= n;i ++)
		if(dis1[i] != inf && dis2[i] != inf)
			ans.insert(con[i] = dis1[i] + (dis2[i] + rate[i] - 1) / rate[i]);
	for(int i = 1;i <= q;i ++){
		int a;ll b;
		scanf("%d%lld",&a,&b);
		if(rate[a] == b || !con[a])
			printf("%lld",*ans.begin());
		else{
			ans.erase(ans.find(con[a]));
			rate[a] = b;
			ans.insert(con[a] = dis1[a] + (dis2[a] + rate[a] - 1) / rate[a]);
			printf("%lld",*ans.begin());
		}
		if(i < q) printf("\n");
	}
	return 0;
}
