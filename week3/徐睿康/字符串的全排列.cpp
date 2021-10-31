#include<bits/stdc++.h>
using namespace std;
int lens,x,y,cnt=0,top=0,sum=1,pan[310];
char a[310],b[310];
string s;
void dfs(int n){
	if(n==lens){
		cnt++;
		for(int i=1;i<=top;i++)cout<<b[i];
		if(cnt!=sum)printf("\n");
		return;
	}
	for(int i=1;i<=lens;i++){
		if(pan[i]==0){
			pan[i]=1;
			b[++top]=a[i];
			dfs(n+1);
			pan[i]=0;
			top--;
		}
	}
}
int main(){
	cin>>s;
	lens=s.length();
	for(int i=1;i<=lens;i++){
		sum*=i;
		a[i]=s[i-1];
	}
	sort(a+1,a+lens+1);
	dfs(0);
	return 0;
}
