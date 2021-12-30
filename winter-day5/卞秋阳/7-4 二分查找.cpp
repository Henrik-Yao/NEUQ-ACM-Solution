#include <bits/stdc++.h>
using namespace std;
int n,a[10086],x,zl=0,ans=0;
int main()
{   cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>x;
	int l=0,r=n-1;
	while(l<=r){
		int mid=(l+r)/2;
		ans++;
		if(x==a[mid]){
		 cout<<mid<<endl;
		 zl=1;
		 break;
	    }
		if(x>a[mid]){l=mid+1;}
		if(x<a[mid]){r=mid-1;}
	}
	if(zl==1)
	{cout<<ans;}
	if(zl==0)
	{
		cout<<"-1"<<endl;
		cout<<ans;
	}
	return 0;
}
