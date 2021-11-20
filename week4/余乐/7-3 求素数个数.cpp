#include <cstdio>
using namespace std;
bool ispn[10000001];
int l,r,n,p=0,ans=0,a[10000001];
int main(){
	for(int i=2;i*2<=10000000;i++){
		if(!ispn[i]) a[++p]=i;
		for(int j=1;j<=p;j++){
			if(i*a[j]>10000000) break;
			ispn[i*a[j]]=1;
			if(!i%a[j]) break;
		}
	}
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		if(!ispn[i]) ans++;
	printf("%d",ans);
	return 0;
} 
