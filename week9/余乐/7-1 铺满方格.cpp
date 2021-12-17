#include <cstdio>
using namespace std;
int n;
long long f[51];
int main(){
	f[1]=1;f[2]=2;f[3]=4;
	for(int i=4;i<=50;i++)
		f[i]=f[i-1]+f[i-2]+f[i-3];
	while(~scanf("%d",&n))
		printf("%lld\n",f[n]);
	return 0;
} 
