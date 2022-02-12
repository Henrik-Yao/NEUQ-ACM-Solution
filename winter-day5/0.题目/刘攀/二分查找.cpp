#include<bits/stdc++.h>
using namespace std;
int a[2000];
int cou=0;
int flag=0;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x;
	cin>>x;
	int l=0;
	int r=n-1;
	while(l<=r){
		cou++;
		int mid=(l+r)/2;
		if(a[mid]>x) r=mid-1;
		else if(a[mid]==x){
			cout<<l<<endl;
			flag=1;
			break;
		}
		else if(a[mid]<x) l=mid+1;
	}
	if(!flag)
	cout<<"-1"<<endl;
	cout<<cou<<endl;
}
