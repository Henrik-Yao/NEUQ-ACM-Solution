#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int main(){long long int a[maxn];
	long long int n;cin>>n;
	int m;cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=m){
			flag=1;
			cout<<i;break;
		}
	}
	if(flag==0) cout<<n+1;
}
