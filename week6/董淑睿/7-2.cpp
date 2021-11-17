#include <bits/stdc++.h>
using namespace std;
const int _=1e6+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
int f(char x) {
	if('0'<=x&&x<='9') return x-'0';
	if(x>='a'&&x<='z') return x-'a'+10;
	if(x>='A'&&x<='Z') return x-'A'+10;
}
string get_hash(string s) {
	int n=s.length()/4,las=s.length()-s.length()/4*4;
	string has;
	// cout<<s<<"! : ";
	for(int i=1,tmp=-1;i<=4;++i,las--) {
		int l=tmp+1,r=tmp+n+(las>0);
		int tot=0;
		for(int j=l;j<=r;++j) tot+=f(s[j]);
		has+=tot%36;
		if(tot%36<10) {
			has+=(char)('0'+tot%36);
			// cout<<char('0'+tot%36)<<" ";
		}
		else {
			has+=(char)('a'+tot%36-10);
			// cout<<char('a'+tot%36-10)<<" ";
		}
		tmp=r;
	}
	// cout<<has<<"!!!\n";
	return has;
}
int main() {
	// freopen("a.in","r",stdin);
	int T=read();
	map<string,string> data;
	while(T--) {
		char s;
		string user,admin;
		cin>>s>>user>>admin;
		if(s=='L') {	
			// if(T==0) {
			// 	// cout<<data[user]<<" "<<admin<<"!\n";
			// 	// cout<<get_hash(data[user])<<" "<<get_hash(admin)<<"\n";
			// }
			if(data[user]==admin) {
				printf("Success!\n");
			} else if(get_hash(data[user])==get_hash(admin)) {
				printf("Attention!\n");
			} else {
				printf("Failed!\n");
			}
		} else {
			if(data.count(user)) {
				printf("Repeated!\n");
			} else {
				data[user]=admin;
				printf("Signed!\n");
			}
		}
	}
	return 0;
}


