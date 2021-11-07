#include <cstdio>
using namespace std;
int n;
long long y(long long a,int b,int c){
	long long ans=1;
	while(b){
		if(b&1) ans=ans*a%c;
		a=a*a%c;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		long long a;int b,c;scanf("%lld%d%d",&a,&b,&c);
		long long ans=y(a,b,c);
		printf("%lld\n",ans);
	}
	return 0;
}
