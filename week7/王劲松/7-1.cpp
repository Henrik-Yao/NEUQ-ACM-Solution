#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,i;
	cin>>n>>m;
	string s1,s2,s;
	map<string,int>cc;
	map<string,string>zd;
	for(i=0;i<n;i++){
		cin>>s1>>s2;
		cc[s2]=1,zd[s2]=s1;
	}
	for(i=0;i<m;i++){
		cin>>s;
		if(cc[s])cout<<zd[s]<<endl;
		else cout<<"eh"<<endl;
	}
	return 0;
}
