#include <queue>
#include <cstdio>
#define inf 999999999
#define N 10001
using namespace std;

int n,m,s,e,top,stack[N],u[N],dis[N],fa[N];

int head[N],p;
struct ss{
	int to,c,ls;
	bool operator < (const ss &r)const{return r.c < c;}
}q[N];
void add(int a , int b , int c){q[++ p] = (ss){b , c , head[a]};head[a] = p;}

void dijkstra(int S){
	for(int i = 0;i < n;i ++)
		dis[i] = inf;
	dis[S] = 0;
	priority_queue<ss> que;
	que.push((ss){S , 0});
	while(!que.empty()){
		ss now = que.top();
		que.pop();
		int x = now.to;
		if(u[x]) continue;
		u[x] = 1;
		for(int i = head[x];i;i = q[i].ls){
			int to = q[i].to;
			if(!u[to] && dis[to] > dis[x] + q[i].c){
				dis[to] = dis[x] + q[i].c;
				fa[to] = x; 
				que.push((ss){to , dis[to]});
			}
		}
	} 
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= (m >> 1);i ++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a , b , c);
		add(b , a , c);
	}
	scanf("%d%d",&s,&e);
	if(s == e){
		printf("%d-->%d:0",s,e);
		return 0;
	} 
	dijkstra(s);
	int x = e;
	stack[++ top] = e;
	while(1){
		stack[++ top] = fa[x];
		x = fa[x];
		if(x == s) break;
	}
	for(int i = top;i >= 1;i --){
		printf("%d",stack[i]);
		if(i > 1) printf("-->");
	}
	printf(":%d",dis[e]);
	return 0;
}
