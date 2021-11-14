#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll a,b,c;
typedef long long LL;
int f(int a,int k,int p){
	int res=1; 
	while(k){
		if(k&1) res=(LL)res*a%p;
		k>>=1;
		a=(LL)a*a%p;
	}
	return res;
}
int main(){
	int t;
	ios::sync_with_stdio(false);
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
		cout<<f(a,b,c)<<endl;
	}
	return 0;
}
