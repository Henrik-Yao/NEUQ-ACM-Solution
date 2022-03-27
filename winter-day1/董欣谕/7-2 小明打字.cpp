#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string str;
	getline(cin,str);
	vector<char> ans;
	int pos=0,flag=1;
	for (int i=0;i<str.length();i++){
		if (str[i]!='['&&str[i]!=']'&&str[i]!='{'&&str[i]!='}'&&str[i]!='-'&&str[i]!='=')
		{
			if (pos==ans.size()-1) ans.push_back(str[i]);
			else if (flag<0) ans[pos]=str[i];
			else ans.insert(ans.begin()+pos,str[i]);
			pos++;
		}
		else if (str[i]=='[') pos=0;
		else if (str[i]==']') pos=ans.size();
		else if (str[i]=='{') {
			if (pos>=1) pos--;
		}
		else if (str[i]=='}') {
			if (pos<=ans.size()-1) pos++;
		}
		else if (str[i]=='-') flag=-flag;
		else {
			if (ans.size()==0) continue;
			ans.erase(ans.begin()+pos-1);
			pos--;
		}
	}
	for (auto ch:ans)
		cout<<ch;
	return 0;
} 
