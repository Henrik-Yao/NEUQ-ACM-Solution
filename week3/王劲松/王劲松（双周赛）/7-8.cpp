#include<bits/stdc++.h>
using namespace std;
int num,ss;
int f(int a[],int l,int r);
int main(){
	int n,i;
	cin>>n>>num;
	int a[n];
	ss=n+1;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	f(a,1,n);
	cout<<ss<<endl;
}
int f(int a[],int l,int r){
	int mid=l+(r-l)/2;
	if(a[mid-1]>=num){
	ss=min(mid,ss);
		if(l!=r){
			f(a,l,mid);
		}
	}
	else if(l>=r){
		return 0;
	}
	
	 if(a[mid-1]<num)f(a,mid+1,r);
	
}
