#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	while(getline(cin,a)) {
		getline(cin,b);
		map<char,bool> mp;		
		for(int i=0; i<b.size(); i++) mp[b[i]] = 1; 
		for(int i=0; i<a.size(); i++) if(mp[a[i]]!=1) cout<<a[i];
		puts("");
	}
    return 0;
}

