#include <cstdio>
#include <cstring>
#define N 1001
using namespace std;
int T,L,R,ans;
int top,stack[N];

int head[N],p;
struct ss{
	int to,ls;
}q[N];
void add(int a , int b){q[++ p] = (ss){b , head[a]};head[a] = p;}

int fa[N];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void build(int now){
	if(top < 0) return;
	if(now == 0){
		top --;
		if(top < 0) return;
	}
	else add(stack[top] , now);
	int a;scanf("%d",&a);
	if(now) stack[++ top] = now;
	build(a);
}

void dfs(int x){
	if(ans) return;
	fa[x] = x;
	for(int i = head[x];i;i = q[i].ls){
		int t = q[i].to;
		dfs(t);
		fa[t] = x;
	}
	if(x == L && fa[R]) ans = find(fa[R]);
	if(x == R && fa[L]) ans = find(fa[L]);
}

int main(){
	scanf("%d",&T);
	while(T --){
		top = 1;ans = 0;
		memset(fa,0,sizeof(fa));
		int a,r;scanf("%d",&r);
		stack[1] = r;
		scanf("%d",&a);
		build(a);
		scanf("%d%d",&L,&R);
		dfs(r);
		printf("%d\n",ans);
	}
	return 0;
}
