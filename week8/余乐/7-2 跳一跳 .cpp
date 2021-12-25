#include <cstdio>
#define N 1000001
using namespace std;
int n,ans,a[N],f[N];
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int p=2,ls,r,tot=0,mr=a[1]+1;
//	printf("%d %d\n",p,mr);
	while(1){
		tot++;
		ls=mr+1;r=mr;
		for(int i=p;i<=r;i++)
			mr=max(mr,i+a[i]);
//		printf("%d %d",p,mr);
		if(mr>=n){
			ans=tot+1;break;
		}
		p=ls;
	}
//	for(int i=1;i<=3;i++)
//		printf("%d\n",a[i]+i);
	printf("%d",ans);
	return 0;
}
