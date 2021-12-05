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
int n;
char s[_];
string f(int L,int R) {
	string ans="";
	for(int l=L;l<=R;) {
		int r=l;
		if(s[l]=='[') {
			int tot=1;
			while(r<R) {
				r++;
				if(s[r]==']') tot--;
				if(s[r]=='[') tot++;
				if(tot==0) break;
			}
			int gs=0;
			string tmp="";
			if(isdigit(s[l+2])) {
				gs=(s[l+1]-'0')*10+s[l+2]-'0',tmp=f(l+3,r-1);
			} else {
				gs=s[l+1]-'0',tmp=f(l+2,r-1);
			}
			for(int j=1;j<=gs;++j) ans+=tmp;
			l=r+1;
		} else {
			ans+=s[l];
			l++;
		}
	}
	return ans;
}
int main() {
	cin>>(s+1);
	n=strlen(s+1);
	cout<<f(1,n);
	return 0;
}