#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],b[1000010],sum,cnt;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m>=n){
		cout<<n;
		return 0;
	}
	sum=n;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1]-1;
		sum+=b[i];
	}
	sort(b+2,b+n+1);
	cnt=1;
	if(cnt!=m)
	for(int i=n;i>=2;i--){
		sum-=b[i];
		cnt++;
		if(cnt==m)break;
	}
	cout<<sum;
	return 0;
}
