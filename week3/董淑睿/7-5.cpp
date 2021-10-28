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
int main() {
	int T=read();
	while(T-->0) {
		std::vector<int> a;
		int n=read();
		for(int i=1;i<=n;++i) a.push_back(read());

		int m=read();
		for(int i=1;i<=m;++i) a.push_back(read());
		sort(a.begin(),a.end());
		for(int i=0;i<n+m;++i) {
			cout<<a[i];
			if(i==n+m-1);else cout<<" ";
			
		}cout<<"\n";
	}	
	return 0;
}