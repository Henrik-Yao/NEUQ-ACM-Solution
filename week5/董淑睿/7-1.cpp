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
int n,m,dad[_],mom[_];
char sex[_];
vector<int> f(int x) {
	std::vector<int> dx,ans;
	dx.push_back(x);
	for(int i=1;i<=4;++i) {
		vector<int> tmp;
		for(auto it:dx) {
			if(dad[it]!=-1) tmp.push_back(dad[it]);
			if(mom[it]!=-1) tmp.push_back(mom[it]);
		}
		dx.clear();
		for(auto it:tmp) dx.push_back(it),ans.push_back(it);
	}
	ans.push_back(x);
	return ans;
}
int main() {
	// freopen("a.in","r",stdin);
	n=read();
	for(int i=0;i<=99999;++i) dad[i]=mom[i]=-1;
	for(int i=1;i<=n;++i) {
		int S=read();
		cin>>sex[S];
		dad[S]=read();
		mom[S]=read();
		if(dad[S]!=-1) sex[dad[S]]='M';
		if(mom[S]!=-1) sex[mom[S]]='F';
		// cout<<S<<" "<<sex[i]<<" "<<dad[i]<<" "<<mom[i]<<"\n";
	}
	m=read();
	while(m-->0) {
		int x=read(),y=read();
		if(sex[x]==sex[y]) {
			printf("Never Mind");
		} else {
			vector<int> fx=f(x),fy=f(y);
			// cout<<x<<" "<<y<<"\n";
			// cout<<x<<": ";
			// for(auto tmp:fx) cout<<tmp<<" ";cout<<"\n";
			// cout<<y<<": ";
			// for(auto tmp:fy) cout<<tmp<<" ";cout<<"\n";
			map<int,int> nb;
			for(auto A:fx) nb[A]=1;
			int flag=1;
			for(auto A:fy) {
				if(nb[A]==1) {
					flag=0;
					break;
				}
			}
			if(flag) cout<<"Yes";
			else cout<<"No";
		}
		if(m!=0) cout<<"\n";
	}
	return 0;
}