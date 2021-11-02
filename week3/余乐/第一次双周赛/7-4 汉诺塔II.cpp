#include <cstdio>
#include <cmath>
using namespace std;
int n;
long long a[65];
int main(){
	a[1]=1;a[2]=3;a[3]=5;
	for(int i=4;i<=64;i++){
		long long b,min=(long long)(pow(2,0)*2+a[i-1]*2-1);
		for(int j=1;j<=i-1;j++){
			if(j<=40) b=(long long)(pow(2,j)*2+a[i-j-1]*2-1);
			if(min>b) min=b;
		}
		a[i]=min;
	}
	while(~scanf("%d",&n)) printf("%lld\n",a[n]);
//	for(int i=1;i<=64;i++)
//		printf("%d %lld\n",i,a[i]);
	return 0;
}
