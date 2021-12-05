#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,string> mp;
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		string a,b;
		cin>>a>>b;
		mp[b] = a;
	}
	for(int i=1; i<=m; i++) {
		string a;
		cin>>a; 
		if(mp[a]=="") cout<<"eh"<<endl;
		else cout<<mp[a]<<endl;
	}
    return 0;
}

