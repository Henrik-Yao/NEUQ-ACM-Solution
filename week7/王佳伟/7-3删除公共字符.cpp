#include<bits/stdc++.h>
using namespace std;

int main() {
	string s = "", str = "";
	while(getline(cin, s))	{
		unordered_map<char, bool> ump;
		getline(cin, str);
		for(auto it : str){
			ump[it] = true;
		}
		for(auto it : s){
			if(ump.count(it)){
				continue;
			}
			else cout << it;
		}
		cout << endl;
	}
}
