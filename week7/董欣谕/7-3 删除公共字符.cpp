#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
map<char,int>mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string str1,str2;
	int flag=0;
	while (getline(cin,str1)&&getline(cin,str2)){
		mp.clear();
		if (flag==0) {
			flag=1;
		}
		else {
			cout<<endl;
		}
		for (int i=0;i<str2.length();i++){
			mp[str2[i]]=1;
		}
		for (int i=0;i<str1.length();i++){
			if (mp.find(str1[i])==mp.end()) cout<<str1[i]; 
		}
	}	
	return 0;
} 
