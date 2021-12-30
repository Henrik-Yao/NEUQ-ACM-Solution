#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],b[100010],l,r,mid,ans;
bool check(int x){
	int cnt=1,sum=0;
	for(int i=2;i<=n;i++){
		sum+=b[i];
		if(sum>=x){
			sum=0;
			cnt++;
		}
	}
	if(cnt>=m)return true;
	else return false;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1];
	l=1,r=a[n];
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
