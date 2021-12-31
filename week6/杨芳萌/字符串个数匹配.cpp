#include<bits/stdc++.h>
using namespace std;
int cnt,ans,flag; 
string a,b;
string c[12345];
int main(){
	getline(cin,a);
	getline(cin,b);
	int len  = a.length();
	int lenb = b.length();
	for(int i=0; i<lenb; i++) 
		if(b[i]>='A'&&b[i]<='Z') b[i] = b[i]-'A'+'a';
	for(int i=0; i<len; i++) {
		if(a[i]<'A'||(a[i]>'Z'&&a[i]<'a')||a[i]>'z') {
			if(flag==1) flag=0;
		}
		else {
			if(flag==0) cnt++,flag=1;
			if(a[i]>='A'&&a[i]<='Z') a[i] = a[i]-'A'+'a';
			c[cnt] += a[i];
		}
	}
//	cout<<cnt<<endl;
	for(int i=0; i<=cnt; i++) if(c[i].find(b)!=-1) ans++;
	cout<<ans<<endl;
    return 0;
}

