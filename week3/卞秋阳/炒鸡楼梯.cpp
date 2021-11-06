#include<bits/stdc++.h>
using namespace std;
long long int a[50];
int F(int n){
	
	if(a[n]>=0) return a[n];
	return a[n]=F(n-1)+F(n-2);
	
	
	
}
int main(){int n,m;
    a[1]=0;
	a[2]=1;
	a[3]=2;
	for(int i=4;i<=50;i++){
		a[i]=-1;
	}
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>m;
	cout<<F(m)<<endl;	
	}
	
	
	
}
