#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn];
int Submaxsum(int l,int r){
	if(l==r) return a[l];
	int MAX;
	int mid=(l+r)/2;
	int leftmax=Submaxsum(l,mid);
	int rightmax=Submaxsum(mid+1,r);
	MAX=max(leftmax,rightmax);
	int t=0;
	int left=a[mid];
	for(int i=mid;i>=l;i--){
		t+=a[i];
		left=max(left,t);
	}
	t=0;int right=a[mid+1];
	for(int i=mid+1;i<=r;i++){
		t+=a[i];
		right=max(right,t);
	}
	MAX=max(MAX,left+right);
	return MAX;
}



int main(){
	int n;
	int flag=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0) flag=1;
	}
	if(flag) cout<<Submaxsum(1,n)<<endl;
	else cout<<0;
	
	
	
	
}
