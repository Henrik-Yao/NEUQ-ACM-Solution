#include<bits/stdc++.h>
using namespace std;
int f(int n,string s1,string s2,string s3);
int main(){
	int n;
	string s1,s2,s3;
	cin>>n>>s1>>s2>>s3;
	
	f(n,s1,s2,s3);
	return 0;
}
int f(int n,string s1,string s2,string s3){
	if(n==1){
		cout<<s1<<'-'<<'>'<<s3<<endl;
	}else if(n!=1){
	f(n-1,s1,s3,s2);
	cout<<s1<<'-'<<'>'<<s3<<endl;
	f(n-1,s2,s1,s3);
	}
}
