#include<bits/stdc++.h>
using namespace std;
int n;
map<string , string> node;

int hashh(string a) {
	int tmp[123456],a1=0,a2=0,a3=0,a4=0;
	int len = a.length();
	for(int i=0; i<len; i++) {
		if(a[i]>='0'&&a[i]<='9') tmp[i] = a[i]-'0';
		if(a[i]>='A'&&a[i]<='Z') tmp[i] = a[i]-'A'+10;
		if(a[i]>='a'&&a[i]<='z') tmp[i] = a[i]-'a'+10;
	}
	int l[4], mod = len%4;
	for(int i=0,j=mod; i<4; i++,j--) {
		if(j>0) l[i] = len/4+1;
		else l[i] = len/4;
		if(i) l[i] += l[i-1];
	}
	for(int i=0; i<l[0]; i++) a1 += tmp[i]; a1 %= 36;
	for(int i=l[0]; i<l[1]; i++) a2 += tmp[i]; a2 %= 36;
	for(int i=l[1]; i<l[2]; i++) a3 += tmp[i]; a3 %= 36;
	for(int i=l[2]; i<l[3]; i++) a4 += tmp[i]; a4 %= 36;
	return ((a1*36+a2)*36+a3)*36+a4;
}

int main(){
	cin>>n;
	while(n--) {
		char op;
		string name,pw;
		cin>>op>>name>>pw;
		if(op=='R') {
			if(node[name]=="") {
				node[name] = pw;
				cout<<"Signed!"<<endl;
			} else cout<<"Repeated!"<<endl;
		} else {
			if(node[name]==pw) cout<<"Success!"<<endl;
			else {
				int std = hashh(node[name]);
				int tmp = hashh(pw);
				if(tmp==std) cout<<"Attention!"<<endl;
				else cout<<"Failed!"<<endl;
			}
		}
	}
    return 0;
}

