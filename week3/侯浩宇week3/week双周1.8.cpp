#include<bits/stdc++.h>
using namespace std;
int p=0,ans,a[1000000],m;
void dg(int l,int r){
    if(l==r)  
		return;
    int mid=(l+r)/2;
    dg(l,mid),dg(mid+1,r);
    if(p)return;
    for(int i=l;i<=r;i++)
    if(a[i]>=m){ans=i;p=1;return;}
    return;
}
int main(){
	int n;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	ans=n;
	dg(0,n-1);
	cout<<ans+1;
	return 0;
}
