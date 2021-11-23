#include <bits/stdc++.h>
using namespace std;
string s[10000];int flag=0;int cnt=0;
int main(){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	int ans=0;
	int L1=s1.length();
	int L2=s2.length();
	for(int i=0;i<L2;i++){
		if(s2[i]>='A'&&s2[i]<='Z') s2[i]+=32;
	}
	for(int i=0;i<L1;i++){
		if(s1[i]<'A'||(s1[i]>'Z'&&s1[i]<'a')||s1[i]>'z'){
			flag=1;
		}
		else {
			if(flag==1) cnt++;flag=0;
			if(s1[i]>='A'&&s1[i]<='Z') s1[i]+=32;
			s[cnt]+=s1[i];
		}
	}
	for(int i=0;i<=cnt;i++){
		if(s[i].find(s2)!=string::npos) ans++;
	}
	cout<<ans;
	return 0;
}
