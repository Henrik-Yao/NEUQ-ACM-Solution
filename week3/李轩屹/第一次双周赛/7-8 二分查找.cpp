#include<bits/stdc++.h>  
using namespace std;
const int maxn=1e6+10;
int main(){
	int n,m,a[maxn];
	cin>>n>>m;
	bool p=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]>=m){
			cout<<i;
			p=0;
			break;
		}
	}
	if(p==1) cout<<n+1;
	return 0;
}
