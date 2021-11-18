#include <bits/stdc++.h>
using namespace std;
vector <string> a;
int Ans=0;
int nxt[1000005];

bool Kmp(string a,string b) {
	nxt[0]=-1;
	int la=a.length();
	int lb=b.length();
	int j=-1;
	for (int i=1; i<lb; ++i) {
		while (j>=0&&b[i]!=b[j+1]) j=nxt[j];
		if (b[i]==b[j+1]) ++j;
		nxt[i]=j;
	}
    j=-1;
	for (int i=0; i<la; ++i) {
		while (j>=0&&a[i]!=b[j+1]) j=nxt[j];
		if (a[i]==b[j+1]) ++j;
		if (j==lb-1) return 1;
	}
	return 0;
}

int main() {
	string s="";
	for (char ch; (ch=getchar())!='\n'; ) {
		if (ch<='Z'&&ch>='A') ch+='a'-'A';
		if (ch<='z'&&ch>='a') s+=ch;
		else if (s!="") a.push_back(s),s="";
	}
	if (s!="") a.push_back(s);
	cin>>s;
	int len=s.length();
	for (int i=0; i<len; ++i) if (s[i]<'a') s[i]+='a'-'A';
	len=a.size();
	for (int i=0; i<len; ++i) {
		if (Kmp(a[i],s)) ++Ans;
	}
	cout<<Ans;
	return 0;
}
