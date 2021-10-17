#include<stdio.h>
#include<math.h>
int main(){
	int r,d,n;
	double s;
	scanf("%d%d%d",&r,&d,&n);
	if(d<0){
		d=-d;
	}
	if(n<0){
		n=-n;
	}
	if(n<=r){
		s=2*d-r;
		printf("%.2f",s);
	}else if(n>r){
	
	s=2*sqrt(d*d+(n-r)*(n-r))-r;
		printf("%.2f",s);
	}
	return 0;
}
