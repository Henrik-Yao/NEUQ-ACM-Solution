#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int fm(int c,int b){
	int max=c+1;
	for(int i = c; i<=b;i++){
		if(a[i]>a[c]){
		a[c]=a[i];
		max=i;
		}
	}
	return max;
}
int func(int m,int n){
	int sc=m;
	for(int i = sc;i <= n;i++){
		if(a[i]+i>a[m]+m)
		m=i;
	}
	return m;
}
int main(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	cin>>a[i];
	int k = 0,t=1;
	while(k+a[k]<n-1){
		int p = a[k]+k;
		int s = fm(k,p);
		k=func(s,p-k);
		t++;
	}
	cout<<t;
}
