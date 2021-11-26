#include<bits/stdc++.h>
using namespace std;
map<char,bool>mp;
int main(){
	string a,b;
	while(getline(cin,a)&&getline(cin,b)){
		int len1=a.size();
		int len2=b.size();
		for(int i=0;i<len2;i++){
			mp[b[i]]=1;
		}
		for(int i=0;i<len1;i++){
			char ch=a[i];
			if(mp[a[i]]) continue;
			cout<<a[i];
		}
		cout<<endl;
		mp.clear();
	}
}
