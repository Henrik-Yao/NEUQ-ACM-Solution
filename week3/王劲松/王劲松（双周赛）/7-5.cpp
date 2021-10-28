#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,n1,n2,j,k;
	cin>>n;
	for(;n>0;n--){
		cin>>n1;
		int a[n1];
		for(j=0;j<n1;j++){
			cin>>a[j];
		}
		cin>>n2;
		int b[n2];
		for(k=0;k<n2;k++){
			cin>>b[k];
		}
		int c[n1+n2];
		int i=0;
		for(j=0,k=0;j<n1&&k<n2;i++){
			if(a[j]<=b[k]){
				c[i]=a[j++];
			}else c[i]=b[k++];
		}
		while(j<n1){
			c[i++]=a[j++];
		}
		while(k<n2){
			c[i++]=b[k++];
		}
		for(i=0;i<n1+n2;i++){
			if(i<n1+n2-1){
				cout<<c[i]<<' ';
			}else cout<<c[i]<<endl;
		}
	}
	return 0;
}
