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
string a,b;
int t[1010];
int main() {
	// freopen("a.in","r",stdin);
	while(getline(cin,a)&&getline(cin,b)) {
		for(int i=0;i<b.length();++i) t[b[i]]++;
		for(int i=0;i<a.length();++i)
			if(!t[a[i]]) cout<<a[i];
		for(int i=0;i<b.length();++i) t[b[i]]--;
		cout<<"\n";
	}
	return 0;
}
