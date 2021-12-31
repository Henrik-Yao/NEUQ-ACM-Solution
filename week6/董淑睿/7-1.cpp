#include <bits/stdc++.h>
using namespace std;
const int _=1e6+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
char s[_],t[_];
int len_s,len_t,fail[_];
void get_fail() {
	int p=0;
	for(int i=2;i<=len_t;++i) {
		while(p>0&&t[p+1]!=t[i]) p=fail[p];
		if(t[p+1]==t[i]) p++;
		fail[i]=p;
	}
}
int main() {
	scanf("%s%s",s+1,t+1);
	len_s=strlen(s+1);
	len_t=strlen(t+1);
	get_fail();
	int p=0,ans=0;
	for(int i=1;i<=len_s;++i) {
		while(p>0&&t[p+1]!=s[i]) p=fail[p];
		if(t[p+1]==s[i]) p++;
		if(p==len_t) {
			ans++;
			p=fail[p];
		}
	}
	cout<<ans<<"\n";
	return 0;
}