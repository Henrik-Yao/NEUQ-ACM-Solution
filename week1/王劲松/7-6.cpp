#include<stdio.h>
typedef struct {
	int v;
	int t;
}jgou;
int main(){
	int i,n,tt;
	scanf("%d%d",&n,&tt);
	jgou xx[n];
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d%d",&xx[i].v ,&xx[i].t );
	}
	for(i=0;i<n;i++){
		if(xx[i].t >tt){
			a[i]=xx[i].v -(xx[i].t -tt);
		}else a[i]=xx[i].v ;
	}
	for(i=1;i<n;i++){
		if(a[0]<a[i]){
			int s=a[0];
			a[0]=a[i];
			a[i]=s;
		}
	}
	printf("%d",a[0]);
	return 0;
}
