#include<bits/stdc++.h>
using namespace std;
int cnt,ans,flag;
const int maxn=1e5+10;
string t,p;
string s[maxn];
int main() {
	getline(cin,t);
	getline(cin,p);
	int tl=t.length();
	int pl=p.length();
	for(int i=0;i<pl;i++)
	if(p[i]>='A'&&p[i]<='Z') p[i]=p[i]-'A'+'a';
	for(int i=0;i<tl;i++){
		if(t[i]<'A'||t[i]>'Z'&&t[i]<'a'||t[i]>'z'){
			if(flag==1) flag=0;
		}
		else{
			if(flag==0) cnt++,flag=1;
			if(t[i]>='A'&&t[i]<='Z') t[i]=t[i]+'a'-'A';
			s[cnt]+=t[i];
		}
	}
	for(int i=0;i<=cnt;i++) if(s[i].find(p)!=-1) ans++;
	cout<<ans<<endl;
	return 0;
}
 



