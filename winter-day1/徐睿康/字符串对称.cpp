#include<bits/stdc++.h>
using namespace std;
string s;
int len,flag;
int main(){
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]!=s[len-i-1])flag=1;
	}
	if(flag==1)cout<<"no";
	else cout<<"yes";
	return 0;
}
