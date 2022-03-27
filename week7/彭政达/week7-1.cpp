#include<bits/stdc++.h>
using namespace std;
map<string,string> ma;
int main(){
	ios::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	string a,b;
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		ma[b]=a;
	}
	while(m--){
		string c;
		cin>>c;
		if(ma[c].size()==0) cout<<"eh"<<endl;
		else cout<<ma[c]<<endl;
	}
}

