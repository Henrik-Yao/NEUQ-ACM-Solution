#include <cstdio>
using namespace std;
bool ispn[10001];
int l,r,p=0,a[10001];
int main(){
	for(int i=2;i*2<=10000;i++){
		if(!ispn[i]) a[++p]=i;
		for(int j=1;j<=p;j++){
			if(i*a[j]>10000) break;
			ispn[i*a[j]]=1;
			if(!i%a[j]) break;
		}
	}
	while(~scanf("%d%d",&l,&r)){
		int tot=0;
		for(int i=l;i<=r;i++)
			if(!ispn[i]) tot++;
		for(int i=l;i<=r;i++)
			if(!ispn[i]){
				printf("%d",i);
				tot--;
				if(tot) printf(" ");
			}
		printf("\n");
	}
	return 0;
} 
