#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e5+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
int n,m;
map<string,string>dsr;
int main() {
	n=read(),m=read();
	for(int i=1;i<=n;++i) {
		string a,b;
		cin>>a>>b;
		dsr[b]=a;
	}
	for(int i=1;i<=m;++i) {
		string a;
		cin>>a;
		if(dsr.count(a)) cout<<dsr[a]<<"\n";
		else cout<<"eh\n";
	}
	return 0;
}