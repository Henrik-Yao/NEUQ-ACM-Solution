#include<bits/stdc++.h>  
using namespace std;
const int maxn=1e5+10;
int main(){
	int t;
	cin>>t;
	while(t--){
		int m,n,a[1000];
		cin>>m;
		for(int i=0;i<m;i++) cin>>a[i];
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[m+i];
		sort(a,a+m+n);
		for(int i=0;i<m+n-1;i++) cout<<a[i]<<" ";
		cout<<a[m+n-1]<<endl;
	}
	return 0;
}

