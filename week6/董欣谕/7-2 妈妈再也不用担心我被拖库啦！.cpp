#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
typedef long long ll;
map<char,int>mp;
map<string,string>realpswd,hashpswd;
string str1,str2;
char chcalc(int l,int r,string str){
	int sum=0;
	for (int i=l;i<=r;i++)
		sum+=mp[str[i]];
	sum%=36;
	if (sum<10) return '0'+sum;
	else return 'a'+sum-10;
}
string calc(string str){
	int len=str.length();
	int a,b,c,d;
	if (len%4==1){
		a=len/4+1;
		b=c=d=len/4;
	}
	if (len%4==2){
		a=b=len/4+1;
		c=d=len/4;
	}
	if (len%4==3){
		a=b=c=len/4+1;
		d=len/4;
	}
	if (len%4==0){
		a=b=c=d=len/4;
	}
	string ans="0000";
	ans[0]=chcalc(0,a-1,str);
	ans[1]=chcalc(a,a+b-1,str);
	ans[2]=chcalc(a+b,a+b+c-1,str);
	ans[3]=chcalc(a+b+c,len-1,str);
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	char oper;
	for (char i='0';i<='9';i++)
		mp[i]=i-'0';
	for (char ch='a';ch<='z';ch++)
		mp[ch]=mp[ch-32]=(int)ch-'a'+10;
	int n;
	cin>>n;
	string temp;
	for (int i=0;i<n;i++){
		cin>>oper>>str1>>str2;
		temp=calc(str2);
		if (oper=='R') {
			if (hashpswd.find(str1)==hashpswd.end()) {
				realpswd[str1]=str2;
				hashpswd[str1]=temp;
				cout<<"Signed!"<<endl;
			}
			else {
				cout<<"Repeated!"<<endl;
			}
		}
		else {
			if (str2==realpswd[str1]) cout<<"Success!"<<endl;
			else if (temp==hashpswd[str1]) cout<<"Attention!"<<endl;
			else cout<<"Failed!"<<endl;
		}
	}
	return 0;
} 