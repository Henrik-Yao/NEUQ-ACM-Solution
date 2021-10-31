#include<bits/stdc++.h>
using namespace std;
long long a [1000001];
long long b [1000001];
long  long c[1000001];
long long d[2000002];
int main(){
	long long n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
		d[n+i]=b[i];
	}
	sort(d+1,d+n+m+1);
	for(int i=1;i<=n+m;i++){
		cout<<d[i];
		if(i!=n+m) cout<<" ";
	}
	cout<<endl;
}
}
