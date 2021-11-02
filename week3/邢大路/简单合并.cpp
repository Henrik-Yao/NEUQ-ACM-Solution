#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,T;
	cin>>T;
	for(int k=0;k<T;k++){
	
	cin>>n;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	int b[m+2];
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	int c[m+n+2];
	int index=1;
	int a_index=1;
	int b_index=1;
	while(a_index<=n&&b_index<=m){
		if(a[a_index]<=b[b_index]){
			c[index]=a[a_index];
			index++;
			a_index++;
		}
		else{
			c[index]=b[b_index];
			index++;
			b_index++;
		}
	}
	while(a_index<=n){
		c[index]=a[a_index];
		index++;
		a_index++;
	}
	while(b_index<=m){
		c[index]=b[b_index];
		index++;
		b_index++;
	}
	for(int i=1;i<=index-1;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
}
	return 0;
	
}
