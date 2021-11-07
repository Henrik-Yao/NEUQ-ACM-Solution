#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[50]; 
int main(){
	ll n,m;
	cin>>n;
	f[1]=1;
	f[2]=1;
	for (int i=3;i<=40;i++)
		f[i]+=f[i-1]+f[i-2];
	for (int i=1;i<=40;i++)
		cout<<f[i]<<endl;
	while (n--){
		cin>>m;
		cout<<f[m]<<endl;
	}
	return 0;
}
