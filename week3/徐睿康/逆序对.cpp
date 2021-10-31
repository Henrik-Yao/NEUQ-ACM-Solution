#include<bits/stdc++.h>
using namespace std;
long long cnt=0,n,a[1000010],temp[1000010];
void merge(long long l,long long r){
	if(l>=r)return;
	long long mid=(l+r)/2;
	merge(l,mid);
	merge(mid+1,r);
	long long pl=l,pr=mid+1,top=0;
	while(pl<=mid&&pr<=r){
		if(a[pl]<=a[pr])temp[top++]=a[pl++];
		else{
			temp[top++]=a[pr++];
			cnt+=mid-pl+1;
		}
	}
	while(pl<=mid)temp[top++]=a[pl++];
	while(pr<=r)temp[top++]=a[pr++];
	for(long long i=0;i<top;i++)a[i+l]=temp[i];
}

int main(){
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	merge(1,n);
	printf("%lld",cnt);
	return 0;
}
