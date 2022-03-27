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
	cin>>str;
	int pos=0;
	while (pos<str.length()){
		if (str[pos]>='A'&&str[pos]<='Z') {
			if (str[pos]=='A') cout<<"sae";
			else if (str[pos]=='B') cout<<"tsaedsae";
			pos++;
		}
		else if (str[pos]=='('){
			char ch=str[pos+1];
			cout<<ch;
			int index;
			for (int i=pos;i<str.length();i++)
				if (str[i]==')') {
					index=i;
					break;
				}
			pos+=2;
			reverse(str.begin()+pos,str.begin()+index);
			while (pos<index){
				cout<<str[pos]<<ch;
				pos++;
			}
			pos++;
		}
		else break;
	}
	return 0;
} 
