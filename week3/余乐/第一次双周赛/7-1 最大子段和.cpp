#include <cstdio>
#define N 10001
using namespace std;
int n,ans,a[N];
int find(int l,int r){
	if(l==r) return a[l];
	int mid=l+(r-l)/2;
	int L=find(l,mid),R=find(mid+1,r),M,tot=0,max1=0,max2=0;
	for(int i=mid;i>=l;i--){
		tot+=a[i];
		if(tot>max1) max1=tot;
	}
	tot=0;
	for(int i=mid+1;i<=r;i++){
		tot+=a[i];
		if(tot>max2) max2=tot;
	}
	M=max1+max2;
	if(L>M) M=L;
	if(R>M) M=R;
	return M;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=find(1,n);
	printf("%d",ans);
	return 0;
}
