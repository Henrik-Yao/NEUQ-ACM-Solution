#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int _=1e5+7;
int read() {
	int x=0,f=1;char s=getchar();
	for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
	for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
	return x*f;
}
ll f(int x) {
	if(x==1) return 2;
	return f(x-1)*3ll+2; 
}
int main() {
	int n;
	while(scanf("%d",&n)!=EOF)
		cout<<f(n)<<"\n";
	return 0;
}