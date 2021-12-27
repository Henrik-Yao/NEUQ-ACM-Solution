#include<bits/stdc++.h>
using namespace std;
int main(){
	stack<char>zz;
	string ss;
	cin>>ss;
	int n=ss.length();
//	cout<<n;
	int i=n/2;
	for(int j=0;j<i;j++){
		//string s+=ss[j];
		zz.push(ss[j]);
	}
	for(int j=n-i;j<n;j++){
		if(ss[j]!=zz.top()){
			cout<<"no";
			break;
		}
		zz.pop();
		if(j==n-1)cout<<"yes";
	}
	return 0;
}
