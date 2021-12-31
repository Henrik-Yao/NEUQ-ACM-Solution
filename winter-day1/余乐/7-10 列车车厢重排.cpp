#include <cstdio>
using namespace std;
int a[101],b[101],q[101],top,n,t,min=0x7fffffff;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(b[t]<a[i]) b[++t]=a[i];
		else{
			int l=1,r=t;
			while(l<=r){
				int mid=l+(r-l)/2;
				if(b[mid]>a[i]) r=mid-1;
				else l=mid+1;
			}
			b[l]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
		if(min>a[i]){
			q[++top]=a[i];
			min=a[i];
		}
	for(int i=1;i<=top;i++){
		printf("%d",q[i]);
		if(i<top) printf(" ");
	}
	printf("\n%d\n",t);
	return 0;
} 
