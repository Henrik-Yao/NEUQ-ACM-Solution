#include<bits/stdc++.h>
using namespace std;
long long n,a[500010],cun[500010],ans=0;
void merge(long long l,long long r){
	if(l>=r)return;
	//cout<<l<<' '<<r<<endl;
	long long mid=(l+r)/2;
	//cout<<mid;
	merge(l,mid);
	merge(mid+1,r);
	long long le=l,ri=mid+1,cnt=0;
	while(le<=mid&&ri<=r){
		cnt++;
		if(a[le]<=a[ri]){
			cun[l+cnt-1]=a[le];
			le++;
		}
		else{
			cun[l+cnt-1]=a[ri];
			ans+=mid-le+1;
			ri++;
		}
	}
	while(le<=mid)cnt++,cun[l+cnt-1]=a[le],le++;
	while(ri<=r)cnt++,cun[l+cnt-1]=a[ri],ri++;
	for(long long i=l;i<=r;i++)a[i]=cun[i];
}
int main(){
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	merge(1,n);
	cout<<ans;
	return 0;
}
