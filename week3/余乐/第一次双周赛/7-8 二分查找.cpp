#include <cstdio>
#define N 1000001
using namespace std;
int n,tar,a[N];
int main(){
	scanf("%d%d",&n,&tar);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(a[mid]<tar) l=mid+1;
		else r=mid-1;
	}
	if(a[l]>=tar) printf("%d",l);
	else printf("%d",n+1);
	return 0;
}
