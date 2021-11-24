#include <bits/stdc++.h>
using namespace std;
int len,top;
int STA[100000];
string s,sta[100000],Ans;
int main() {
    cin>>s;
    len=s.length();
    sta[0]="";
    for (int i=0; i<len; ) {
    	if (s[i]=='[') {
    		sta[++top]="";
    		for (++i,STA[top]=0; isdigit(s[i]); ++i)
				STA[top]=STA[top]*10+s[i]-48;
		} else if (s[i]==']') {
			for (int j=1; j<=STA[top]; ++j) sta[top-1]+=sta[top];
			--top,++i;
		} else {
			sta[top]+=s[i];
			++i;
		}
	}
	cout<<sta[0];
    return 0;
}
