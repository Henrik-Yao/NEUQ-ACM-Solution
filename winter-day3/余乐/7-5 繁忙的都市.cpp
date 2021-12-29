#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 15001
using namespace std;

int n,e;

int fa[N];
int find(int x){
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return x;
}

struct ss{
	int x,y,c;
}q[N];
bool cmp(const ss &a , const ss &b){
	return a.c < b.c;
}

int main(){
	scanf("%d%d",&n,&e);
	int ans = 0,maxn = 0;
	for(int i = 1;i <= e;i ++)
		scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].c);
	sort(q , q + e + 1 , cmp);
	for(int i = 1;i <= n;i ++)
		fa[i] = i;
	for(int i = 1;i <= e;i ++){
		int x = q[i].x,y = q[i].y;
		int fx = find(x),fy = find(y);
		if(fx != fy){
			ans ++;
			if(maxn < q[i].c) maxn = q[i].c;
			fa[fx] = fy;
		}
	}
	printf("%d %d",ans,maxn);
	return 0;
}
