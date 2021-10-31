#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=4e6+1e2;
char s[maxn];
string a;
int n,m;
int main(){
	cin>>n;
	scanf("%s",s+1);
	int now=strlen(s+1) ;
	for(int i=1;i<=n;i++)
	{int num=0;
	cin>>a;
	int len=a.length();
	for(int i=1;i<=now-len+1;i++)
	{
		string b;
		b.clear();
		for(int j=i;j<=i+len-1;j++)
		b+=s[j];
		if(a==b)++num;
	 } cout<<num;
	 if(i!=m)cout<<"\n";
	}return 0;
}//learn from hhj
