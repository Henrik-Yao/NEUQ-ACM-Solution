#include <queue>
#include <cstdio>
#include <cstring>
#define N 101
using namespace std;

int n,m,d[N],u[N],f[N][N];
queue<int> q;

int main(){
	while(~scanf("%d%d",&n,&m)){
		memset(u , 0 , sizeof(u));
		memset(d , 0 , sizeof(d));
		memset(f , 0 , sizeof(f));
		for(int i = 1;i <= m;i ++){
			int a,b;
			scanf("%d%d",&a,&b);
			f[a][b] = 1;
			d[b] ++;
		}
		int ans = 0;
		while(1){
			int id = 0,tot = 0;
			for(int i = 1;i <= n;i ++)
				if(d[i] == 0 && u[i] == 0){
					q.push(i);
					tot ++;
					u[i] = 1;
				}
			while(!q.empty()){
				int x = q.front();q.pop();
				for(int i = 1;i <= n;i ++)
					if(f[x][i])
						d[i] --;
			}
			if(ans < tot) ans = tot;
			if(tot == 0) break;
		}
		for(int i = 1;i <= n;i ++)
			if(d[i]){
				ans = 0;
				break;
			}
		if(ans <= 1) printf("%d\n",ans);
		else printf("2\n");
	} 
	return 0;
}
