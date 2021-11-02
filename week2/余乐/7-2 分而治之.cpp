#include <cstdio>
#define N 10001
using namespace std;
int n,m,a[N],b[N],c[N],k;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int l;scanf("%d",&l);
		for(int j=1;j<=n;j++) c[j]=0;
		for(int j=1;j<=l;j++){
			int d;scanf("%d",&d);
			c[d]=1;
		}
		int d;
		for(int j=1;j<=m;j++){
			d=c[a[j]]+c[b[j]];
			if(d==0) break;
		}
		if(d==0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
