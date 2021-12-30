#include<bits/stdc++.h>
using namespace std;
int n,x,a[1010],l,r,mid,flag,cnt=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>x;
	l=1,r=n;
	flag=-1;
	while(l<=r){
		cnt++;
		mid=(l+r)/2;
		if(a[mid]==x){
			flag=mid;
			break;
		}
		else if(a[mid]<x)l=mid+1;
		else r=mid-1;
	}
	if(flag==-1)cout<<-1<<endl<<cnt;
	else cout<<flag-1<<endl<<cnt;
	return 0;
}
