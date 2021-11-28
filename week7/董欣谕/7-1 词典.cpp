#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
map<string,string>mp;
string str1,str2,str;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>str1>>str2;
		mp[str2]=str1;
	}
	for (int i=1;i<=m;i++){
		cin>>str;
		if (mp.find(str)!=mp.end()) cout<<mp[str]<<endl;
		else cout<<"eh"<<endl;
	}
	return 0;
} 
