#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int main(){
	int n,N;
	cin>>n>>N;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[n]<N) cout<<n+1;
	else for(int i=1;i<=n;i++){
		if(a[i]>=N) {
			cout<<i<<endl;break;
		}
	}
	
	return 0; 
}
