#include <cstdio>
#include <cstring>
#define N 101
using namespace std;

int n,e,f[N][N];

int main(){
	while(~scanf("%d%d",&n,&e)){
		for(int i = 0;i < n;i ++)
			for(int j = 0;j < n;j ++)
				f[i][j] = 9999999;
		for(int i = 1;i <= e;i ++){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			f[a][b] = f[b][a] = c;
		}
		for(int k = 0;k < n;k ++)
			for(int i = 0;i < n;i ++)
				for(int j = 0;j < n;j ++)
					if(f[i][j] > f[i][k] + f[k][j])
						f[i][j] = f[i][k] + f[k][j];
		int minn = 0x7fffffff,p;
		for(int i = 0;i < n;i ++){
			int tot = 0;
			for(int j = 0;j < n;j ++)
				if(i != j)
					tot += f[i][j];
			if(minn > tot){
				minn = tot;
				p = i;
			}
		}
		printf("%d\n",p);
	}
	return 0;
}
