
#include<stdio.h>

int main(){
	int n;
	int s1=0,s2=0;
	scanf("%d",&n);
	char a[50000];
	scanf("%s",a);
	int num0=0,i,cnt,cntt;
	for(i=0;a[i]!=0;i++,num0++){
	}
	for(i=0;i<n;i++){
		char b[20];
		scanf("%s",b);
		int num1=0;
		for(cnt=0;b[cnt]!=0;cnt++,num1++){
		}
		for(s1=0,cnt=0;cnt<num0;cnt++){
			if(a[cnt]==b[0]&&num1<=num0-cnt){
				int tt=cnt;
				for(cntt=0;cntt<num1;tt++,cntt++){
					if(a[tt]!=b[cntt]){
						break;
					}
					if(cntt==num1-1){
						s1++;
					}
				}
			}	
		}if(i<n-1){
		printf("%d\n",s1);
		}else printf("%d",s1);
	}
	return 0;
}
