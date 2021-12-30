#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],x,ans1;
void f(int l,int r){
	if(l<=r){
	if(x==a[(l+r)/2]){
		ans1=(l+r)/2;
		return ;
	}
	else if(x>a[(l+r)/2])
	f((l+r)/2+1,r);
	else 	f(l,(l+r)/2-1);	
	}
}
int main(){
	while(cin>>n){
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i<n)cout<<" ";
	}
	
	cout<<endl;
	cin>>m;
	for(int i=0;i<m;i++){
	cin>>x;
	ans1=0;
	f(1,n);	
	cout<<ans1;
	if(i<m-1)cout<<" ";
	}
	cout<<endl;	
	}
	return 0;
}
