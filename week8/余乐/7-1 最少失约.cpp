#include <cstdio>
#include <cstring>
using namespace std;
int T,n,f[24][24];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&T);
	for(int p=1;p<=T;p++){
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			f[a][b]=1;
		}
		for(int len=2;len<=23;len++)
			for(int j=0;j<=23-len;j++)
				for(int k=j+1;k<j+len;k++)
					f[j][j+len]=max(f[j][j+len],f[j][k]+f[k][j+len]);
		printf("%d\n",n-f[0][23]);
	}
	return 0;
} 
