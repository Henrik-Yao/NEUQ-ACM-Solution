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
	while (cin>>str){
		while (st.size()!=0) st.pop();
		int cnt=0;
		for (auto ch:str){
			if (ch=='(') st.push(ch);
			else {
				if (st.size()!=0&&st.top()=='(') st.pop();
				else cnt++;
			}
		}
		if (st.size()==0&&cnt==0)
			cout<<"Match";
		else {
			cout<<cnt+st.size()<<endl;
			for (int i=0;i<cnt;i++)
				cout<<"(";
			cout<<str;
			for (int i=0;i<st.size();i++)
				cout<<")";
		}
		cout<<endl;
	}	
	return 0;
} 
