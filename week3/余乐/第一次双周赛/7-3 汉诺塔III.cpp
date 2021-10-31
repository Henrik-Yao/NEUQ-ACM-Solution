#include <cstdio>
using namespace std;
int n;
long long a[36];
int main(){
	a[1]=2;
	for(int i=2;i<=35;i++) a[i]=a[i-1]*3+2;
	while(~scanf("%d",&n)){
		printf("%lld\n",a[n]);
	}
	return 0;
}
