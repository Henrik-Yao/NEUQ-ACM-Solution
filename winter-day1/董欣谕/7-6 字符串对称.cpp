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
	int flag=0;
	for (int i=0,j=str.length()-1;i<j;i++,j--)
		if (str[i]!=str[j]) flag=1;	
	if (flag) cout<<"no";
	else cout<<"yes";
	return 0;
} 
