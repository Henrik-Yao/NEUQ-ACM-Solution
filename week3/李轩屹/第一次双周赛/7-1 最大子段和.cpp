#include<bits/stdc++.h>  
using namespace std;
const int maxn=1e4+10;
int n,a[maxn];
int max(int a,int b,int c){
	if(a>=b&&a>=c) return a;
	else if(c>=b&&c>=a) return c;
	else return b;
}
int merge(int *a,int l,int r){
	int m=(l+r)/2;
	if(l==r) return a[l];
	int x=merge(a,l,m);
	int y=merge(a,m+1,r);
	int maxl=0,maxr=0;
	int temp=0;
	for(int i=m+1;i<=r;i++){
		temp+=a[i];
		if(temp>maxr) maxr=temp;
	}
	temp=0;
	for(int j=m;j>=l;j--){
		temp+=a[j];
		if(temp>maxl) maxl=temp;
	}
	int maxlr=maxl+maxr;
	return max(maxlr,x,y);
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<merge(a,0,n-1);
	return 0;
}
