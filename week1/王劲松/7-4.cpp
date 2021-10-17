#include<stdio.h>
int f(int n);
int main(){
	int n,i;
	scanf("%d",&n);
	printf("%d",f(n));
	
	return 0;
}
int f(int n){
	int a[n+1];
	int m,cnt;
	for(m=0;m<n+1;m++){
		a[m]=0;
	}
	a[1]=1;
	for(m=2;m<=n;m++){
		for(cnt=1;cnt<m;cnt++){
			if(m%cnt==0){
			a[m]+=a[cnt];	
			}
		}
		a[m]++;
	}
	return a[n];
}
