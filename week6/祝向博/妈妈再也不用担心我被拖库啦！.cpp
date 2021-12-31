#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int N;
char op;
string Name,Password;
map <string,string> mp;


string check(string a) {
	string ret="";
	int len,sum,now;
	int blk[4];
	len=a.length();
	for (int i=0; i<4; ++i) blk[i]=len/4;
	for (int i=0; i<len-4*(len/4); ++i) blk[i]++;
	for (int i=0,j=0,k; i<4; ++i) {
		now=0,k=j+blk[i]-1;
		for (; j<=k; ++j) {
			if (isdigit(a[j])) now+=a[j]-'0';
			else if (a[j]>='a') now+=a[j]-'a'+10;
			else now+=a[j]-'A'+10;
			now%=36;
		}
		if (now<10) ret+='0'+now;
		else ret+='a'+now-10;
	}
	return ret;
}

int main() {
	cin>>N;
	for (int i=1; i<=N; ++i) {
		cin>>op>>Name>>Password;
		if (op=='R') {
			if (mp[Name]=="")
				mp[Name]=Password,cout<<"Signed!"<<endl;
			else
				cout<<"Repeated!"<<endl;
		} else {
			if (mp[Name]==Password)
				cout<<"Success!"<<endl;
			else
				if (check(mp[Name])==check(Password))
					cout<<"Attention!"<<endl;
				else
					cout<<"Failed!"<<endl;
		}
	}
	return 0;
}
