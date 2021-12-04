#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],minn=2147483646,ans=0;
void dt(int space){
	if(space==0){
		minn=min(minn,ans);
		return;
	}
	for(int i=0;i<space;i++){
		if(a[i]>=space-i){
		ans++;dt(i);break;	
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	dt(n-1);
	cout<<minn;
	return 0;
}
