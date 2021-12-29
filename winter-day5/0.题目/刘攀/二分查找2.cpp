#include<bits/stdc++.h>
using namespace std;
int n;
int a[200];
int flag=0;
int main(){
	while(cin>>n){
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		int m;
		cin>>m;
		int x;
		for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i!=n) cout<<" ";
		}
		cout<<endl;
		for(int i=1;i<=m;i++){
			cin>>x;
			int l=1;
			int r=n;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid]==x){
					cout<<mid;
					if(i!=m) cout<<" ";
					flag=1;
					break;
				}
				else if(a[mid]>x) r=mid-1;
				else if(a[mid]<x) l=mid+1;
			}
		if(!flag){
		cout<<"0";
		if(i!=m) cout<<" ";
	}
		flag=0;
		}
		cout<<endl;
	}
}
