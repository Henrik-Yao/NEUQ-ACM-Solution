#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
stack<char>st;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string str;
	cin>>str;
	int flag=0;
	for (int i=0;i<str.length();i++){
		if (str[i]=='('||str[i]==')'||str[i]=='['||str[i]==']'||str[i]=='{'||str[i]=='}'){
			if (str[i]=='('||str[i]=='['||str[i]=='{'){
				st.push(str[i]);
			}
			else if (str[i]==')'){
				if (st.size()==0||st.top()!='(') {
					flag=1;
					break;
				}
				else st.pop();
			}
			else if (str[i]==']'){
				if (st.size()==0||st.top()!='['){
					flag=1;
					break;
				}
				else st.pop();
			}
			else if (str[i]=='}'){
				if (st.size()==0||st.top()!='{'){
					flag=1;
					break;
				}
				else st.pop();
			}
		}
	}
	if (flag||st.size()!=0) cout<<"no";
	else cout<<"yes";
	return 0;
} 
