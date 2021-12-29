#include <cstdio>
#define N 500001 
using namespace std;
int n,c,a[N],b[N];
long long ans=0;
void sort(int l,int r){
	if(l==r) return;
	int mid=l+(r-l)/2;
	sort(l,mid);
	sort(mid+1,r);
	int len=r-l+1,p1=l,p2=mid+1;
	for(int i=1;i<=len;i++){
		if(p1<=mid&&p2<=r) {
			if(a[p1]<=a[p2]){
				b[i]=a[p1++];
				ans+=p2-mid-1;
			}
			else b[i]=a[p2++];
		}
		else {
			if(p1<=mid){
				b[i]=a[p1++];
				ans+=p2-mid-1;
			} 
			if(p2<=r) b[i]=a[p2++];
		}
	}
	for(int i=l;i<=r;i++) a[i]=b[i-l+1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(1,n);
	printf("%lld",ans);
	return 0;
}
