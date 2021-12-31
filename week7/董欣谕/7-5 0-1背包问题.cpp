#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
int v[401],w[401],f[1501];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,c;
	while (cin>>n>>c){
		memset(f,0,sizeof f);
		for (int i=1;i<=n;i++)
			cin>>w[i];
		for (int i=1;i<=n;i++)
			cin>>v[i];
		for (int i=1;i<=n;i++)
			for (int j=c;j>=w[i];j--)
				f[j]=max(f[j-w[i]]+v[i],f[j]);
		cout<<f[c]<<endl;
	}	
	return 0;
} 
