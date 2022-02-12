#include <cstdio>
using namespace std;
int n,m,k,v[1001];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int sum=n,p=1;
	while(sum){
		int t=m-1;
		while(t){
			p--;if(p<1) p=n;
			if(v[p]==0) t--;
		}
		printf("%d ",p);sum--;v[p]=1;
		t=k-1;
		while(t){
			p++;if(p>n) p=1;
			if(v[p]==0) t--;
		}
		printf("%d ",p);sum--;v[p]=1;
	}
	printf("\n");
	return 0;
}
