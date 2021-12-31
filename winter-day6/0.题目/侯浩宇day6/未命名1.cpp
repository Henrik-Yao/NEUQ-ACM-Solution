#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(cin>>n){
		int a[101];
		for(int i=0;i<n;i++)
		cin>>a[i];

		for(int i=1;i<n;i++){
			for(int j=i-1;j>=0;j--){
				
				if(a[j]>a[j+1])swap(a[j],a[j+1]);
			}
			for(int j=0;j<n;j++){
				cout<<a[j];
				if(j<n-1)cout<<" ";
			}
			
			cout<<endl;
		}
	}
	return 0;
}
