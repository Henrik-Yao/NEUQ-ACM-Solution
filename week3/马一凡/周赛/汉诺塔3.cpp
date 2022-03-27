#include <iostream>
#include<cmath>
using namespace std;


int main()
{
	int n,i;
    long long f[36]={0};
	f[1]=2;
	for(int i=2;i<=36;i++) f[i]=3*f[i-1]+2;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",f[n]);
	}
    return 0;
}
