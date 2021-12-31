#include<bits/stdc++.h>
using namespace std;
void f(int j,int k);
int a[1000000],n,maxx;
int main(){
	int i;
	cin>>n;
	maxx=n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	f(0,0);
	cout<<maxx;
	return 0;
}
void f(int j,int k){
	if(a[j]+j>=n-1){
		maxx=min(maxx,k+1);
		return;
	}
	int wz=j+1,fmax=a[j+1]+j+1;
	for(int m=2;m<=a[j]&&j+m<=n-1;m++){
		if(a[j+m]+j+m>fmax){
			fmax=a[j+m]+j+m;
			wz=j+m;
		}
	}
	f(wz,k+1);
}
