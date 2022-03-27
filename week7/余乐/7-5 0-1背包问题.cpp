#include <cstdio>
#include <cstring>
#define N 401
#define C 1501
using namespace std;
int n,c,w[N],v[N],f[N][C];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	while(~scanf("%d%d",&n,&c)){
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			for(int j=0;j<=c;j++)
				if(j>=w[i])
					f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
				else f[i][j]=f[i-1][j];
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<=c;j++)
//				printf("%d ",f[i][j]);
//			printf("\n");
//		} 
		printf("%d\n",f[n][c]);
	}
	return 0;
}
