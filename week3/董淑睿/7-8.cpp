#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e6+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
int main() {
	int n=read(),val=read();	
	for(int i=1;i<=n;++i) {
		int tmp=read();
		if(val<=tmp) {
			cout<<i;
			return 0;
		}
	}
	cout<<n+1;
	return 0;
}