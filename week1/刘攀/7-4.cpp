#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int b[1000010];
int c[1000010];
int d[1000010];
int e[1000010];
int main(){
	int n;
	cin>>n;
	int sum=0;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==0){
		c[i]=c[i-1]+1;
		b[a[i]]=1;
		}
		else c[i]=c[i-1];
	}
	
	for(int i=n;i>=1;i--){
		if(d[a[i]]==0){
		e[i]=e[i+1]+1;
		d[a[i]]=1;
		}
		else e[i]=e[i+1];
	}
	
	for(int i=2;i<=n;i++){
		int s=c[i]+e[i+1];
		if(s>maxn) maxn=s;
	}
	cout<<maxn;
}
