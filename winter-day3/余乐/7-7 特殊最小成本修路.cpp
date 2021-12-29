#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1501
using namespace std;

int n[N],e[N],v[N],T;

int fa[N];
int find(int x){
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return x;
}

struct ss{
	int x,y,c;
}q[N][N];
bool cmp(const ss &a , const ss &b){
	return a.c < b.c;
}

int main(){
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c)){
		T ++;
		n[T] = a;v[T] = b;e[T] = c;
		for(int i = 1;i <= e[T];i ++)
			scanf("%d%d%d",&q[T][i].x,&q[T][i].y,&q[T][i].c);
	}
	for(int j = 1;j <= T;j ++){
		int ans = 0,count = 0;
		sort(q[j] , q[j] + e[j] + 1 , cmp);
		for(int i = 0;i < n[j];i ++)
			fa[i] = i;
		for(int i = 1;i <= e[j];i ++){
			int x = q[j][i].x,y = q[j][i].y;
			int fx = find(x),fy = find(y);
			if(fx != fy){
				if((x == v[j] || y == v[j])){
					if(count < 2){
						ans += q[j][i].c;
						fa[fx] = fy;
						count ++;
					}
				}
				else{
					ans += q[j][i].c;
					fa[fx] = fy;
				}
			}
		}
		int flag = 0,F = find(0);
		for(int i = 1;i < n[j];i ++)
			if(F != find(i)){
				flag = 1;
				break;
			}
		if(flag)
			printf("-1");
		else printf("%d",ans);
		if(j < T) printf("\n");
	}
	return 0;
}
