#include<bits/stdc++.h>
using namespace std;


int main() {
	unordered_map<string, string> ump;
	int n, m;
	string voc, res;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> res >> voc;
		ump[voc] = res;
	}
	string now;
	for(int i = 0; i < m; i++){
		cin >> now;
		if(!ump.count(now)) cout << "eh";
		else cout << ump[now];
		if(i != m-1) cout << endl;
	}
	
}


