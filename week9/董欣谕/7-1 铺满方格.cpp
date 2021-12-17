#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
ll f[51];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	f[1]=1;
	f[2]=2;
	f[3]=4;
	for (int i=4;i<=50;i++)
		f[i]=f[i-3]+f[i-2]+f[i-1];
	while (cin>>n){
		cout<<f[n]<<endl;
	}	
	return 0;
} 
