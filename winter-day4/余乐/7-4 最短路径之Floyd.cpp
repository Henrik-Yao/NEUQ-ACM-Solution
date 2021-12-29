#include <cstdio>
#define N 101
#define inf 999999999
using namespace std;

int n,m,top,ans[N],f[N][N],road[N][N];
 
void print(int s , int e){
	int x = s;
	top = 0;
	while(1){
		ans[++ top] = x;
		x = road[x][e];
		if(x == e) break;
	}
	ans[++ top] = e;
	for(int j = 1;j <= top;j ++){
		printf("%d",ans[j]);
		if(j < top) printf("->");
	}
	printf(":%d",f[s][e]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n;j ++)
			f[i][j] = inf,road[i][j] = j; 
	for(int i = 1;i <= m;i ++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		f[a][b] = c;
	}
	for(int k = 0;k < n;k ++)
		for(int i = 0;i < n;i ++)
			for(int j = 0;j < n;j ++)
				if(f[i][j] > f[i][k] + f[k][j]){
					f[i][j] = f[i][k] + f[k][j];
					road[i][j] = road[i][k];
				}
	for(int i = 1;i <= 2;i ++){
		int s,e;
		scanf("%d%d",&s,&e);
		if(s == e){
			printf("%d->%d:0\n",s,e);
			continue;
		} 
		if(f[s][e] == inf){
			printf("%d->%d:-1\n",s,e);
			continue;
		}
		print(s , e);
		printf("\n");
	}
	int maxn = 0,s,e;
	for(int i = 0;i < n;i ++)
		for(int j = 0;j < n;j ++)
			if(f[i][j] != inf && f[i][j] > maxn && i != j){
				maxn = f[i][j];
				s = i;e = j;
			}
	print(s , e);
	return 0;
}
