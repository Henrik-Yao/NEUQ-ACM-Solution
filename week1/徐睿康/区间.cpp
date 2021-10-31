#include<bits/stdc++.h>
using namespace std;
int maxx=-1,n,a[1000010],pan[1000010],pan1[1000010],tong[100010],tong1[100010];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(tong[a[i]]==0){
			tong[a[i]]=1;
			pan[i]=pan[i-1]+1;
		}
		else pan[i]=pan[i-1];
	}
	for(int i=n;i>=1;i--){
		if(tong1[a[i]]==0){
			tong1[a[i]]=1;
			pan1[i]=pan1[i+1]+1;
		}
		else pan1[i]=pan1[i+1];
	}
	for(int i=1;i<n;i++){
		maxx=max(maxx,pan[i]+pan1[i+1]);
	}
	cout<<maxx;
	/*for(int i=1;i<=n;i++){
		cout<<pan[i]<<' ';
	}
	for(int i=1;i<=n;i++){
		cout<<pan1[i]<<' ';
	}*/
}
