#include<bits/stdc++.h>
using namespace std;
map<string,string> MAP;
int n,m;
int main() {
	cin>>n>>m;
	while(n--){
		string a,b;
		cin>>b>>a;
		MAP.insert(std::pair<string,string>(a,b));
	}
	while(m--){
		string c;
		cin>>c;
		if(MAP.count(c)) cout<<MAP[c]<<endl;
		else cout<<"eh"<<endl;
	}
	return 0;
}


