#include<bits/stdc++.h>
using namespace std;
int n,a[1001],x,ans1=-1,ans2=0;
void f(int l,int r){
	if(l<=r){
	ans2++;cout<<a[(l+r)/2];
	if(x==a[(l+r)/2]){
		ans1=(l+r)/2;
		return ;
	}
	else if(x>a[(l+r)/2])
	f((l+r)/2+1,r);
	else f(l,(l+r)/2-1);		
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cin>>x;
	f(0,n-1);
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}
