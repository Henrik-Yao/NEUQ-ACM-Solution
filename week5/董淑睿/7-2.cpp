#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=4e5+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}

bool pd(int n) {
	for(int i=2;i*i<=n;++i)
		if(n%i==0) return 0;
	return 1;
}
int main() {
	int T=read();
	while(T-->0) {
		int x=read();
		if(pd(x)) cout<<"1\n";
		else {
			if(pd(x-2)||x%2==0) cout<<"2\n";
			else cout<<"3\n";
		}
	}
	return 0;
}