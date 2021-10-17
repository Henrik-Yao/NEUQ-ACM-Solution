#include<bits/stdc++.h>
using namespace std;

int len;
void judge(string s, string str){
	int ans = 0;
	int le = str.size();
	while(1){
		if(s.find(str) != string::npos){
			int pos = s.find(str);
			ans++;
			s = s.substr(pos+1, len-(pos+1));	
//			cout << s << endl;
		}
		else break;
	}
	cout << ans << endl;	
}
//jjjsjjjjj

int main() {
	int n;
	cin >> n;
	string s;
	string str;
	cin >> s;
	len = s.size();
	while(n--){
		cin >> str;
		judge(s, str);
	}
}
