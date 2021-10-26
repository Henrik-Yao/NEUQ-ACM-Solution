#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	int n,T,t,v;int a[100000];
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		cin>>v>>t;
		if(t>T){
			a[i]=v-(t-T);
				}
				
		else{a[i]=v;
		}
	}
	sort(a+1,a+n+1);
	cout<<a[n];
	
}
