#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
long long ans=0;
void dg(int begin,int end){
	int mid=(begin+end)/2;
	if(begin==end)return;
	else{
		dg(begin,mid);
		dg(mid+1,end);
		int l=begin;
		int r=mid+1;
		for(int i=begin;i<=end;i++){
		 	if((r>end)||(l<=mid&&a[l]<=a[r]))b[i]=a[l++];
		    else{
		 	    b[i]=a[r++];
		 	    ans=ans+ mid-l+1;
		    }
		}
		for(int i=begin;i<=end;i++){
		 	a[i]=b[i];
		}
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dg(1,n);
    cout<<ans;
	return 0;
}
