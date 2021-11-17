#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string str1,str2,temp;
	getline(cin,str1);
	getline(cin,str2);
	int cnt=0;
	for (int i=0;i<str1.length();i++)
		if (str1[i]>='A'&&str1[i]<='Z') str1[i]+=32;
	for (int i=0;i<str2.length();i++)
		if (str2[i]>='A'&&str2[i]<='Z') str2[i]+=32;
	for (int i=0;i<str1.length()+1;i++){
		if (str1[i]>='a'&&str1[i]<='z') temp+=str1[i];
		else {
			if (temp.find(str2)!=temp.npos) cnt++;
			temp.clear();
		}
	}
	cout<<cnt;
	return 0;
} 
