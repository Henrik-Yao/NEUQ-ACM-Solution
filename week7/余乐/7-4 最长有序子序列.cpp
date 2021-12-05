#include <cstdio>
#define N 1001
using namespace std;
int T,t,n,q[N];
void add(int a){
	if(a>q[t]||t==0) q[++t]=a;
	else{
		int l=1,r=t;
		while(l<=r){
			int mid=l+(r-l)/2;
			if(a>q[mid]) l=mid+1;
			else r=mid-1;
		}
		q[l]=a;
	}
}
int main(){
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d",&n);
		t=0;
		for(int j=1;j<=n;j++){
			int a;scanf("%d",&a);
			add(a);
		}
		printf("%d\n",t);
		if(i<T) printf("\n");
	}
	return 0;
} 
