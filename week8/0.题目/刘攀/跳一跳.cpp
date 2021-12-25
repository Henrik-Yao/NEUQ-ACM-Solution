#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int find(int n,int m){
	int ans=n+1;
	for(int i=n;i<=m;i++){
		if(a[i]>a[n]){
			a[n]=a[i];
			ans=i;
		}
	}
	return ans;
}
int f(int n,int m){
	int ans=n;
	for(int i=ans;i<=m;i++){
		if(a[n]<a[i]+i-n){
			n=i;
		}
	}
	return n;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k=0;
	int len=1;
	while(k+a[k]<n-1){
		int p=a[k];
		int m=find(k,k+a[k]);
		k=f(m,p+k);
		len++;
	}
	cout<<len<<endl;
}
