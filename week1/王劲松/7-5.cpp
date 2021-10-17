#include<stdio.h>
typedef struct {
	int cx;
	char a[1000];
}jgou;
int main(){
	int n,m,i,cnt;
	scanf("%d%d",&n,&m);
	jgou xx[n];
	for(i=0;i<n;i++){
		scanf("%d%s",&xx[i].cx ,&xx[i].a );
	}
	for(cnt=1;m>0;m--){
		
		int j,k;
		scanf("%d%d",&j,&k);
		if(xx[cnt-1].cx==0){
			if(j==0){
			cnt-=k;
			}
			else if(j==1){
				cnt+=k;
			}
			for(;cnt>n;){
				cnt-=n;
			}
			for(;cnt<1;){
				cnt+=n;
			}
			
		}
		else if(xx[cnt-1].cx ==1){
			if(j==0){
			cnt+=k;
			}
			else if(j==1){
				cnt-=k;
			}
				for(;cnt>n;){
				cnt-=n;
			}
			for(;cnt<1;){
				cnt+=n;
			}
		}
	}
	printf("%s",xx[cnt-1].a);
	return 0;
}
