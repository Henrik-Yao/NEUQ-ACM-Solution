#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 1001
using namespace std;

int n,m,f[N][N];

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i = 0;i < n;i ++)
			for(int j = 0;j < n;j ++)
				f[i][j] = 99999;
		for(int i = 1;i <= n;i ++){
			int x,j;
			scanf("%d%d",&x,&j);
			for(int k = 1;k <= j;k ++){
				int b;
				scanf("%d",&b);
				f[x][b] = 1;
			}
		}
		for(int k = 0;k < n;k ++)
			for(int i = 0;i < n;i ++)
				for(int j = 0;j < n;j ++)
					f[i][j] = min(f[i][j] , f[i][k] + f[k][j]);
		for(int i = 1;i <= m;i ++){
			int a,b,ans;
			scanf("%d%d",&a,&b);
			ans = f[a][b];
			if(ans == 99999) printf("connection impossible\n");
			else printf("%d\n",ans);
		}
	}
	return 0;
}
