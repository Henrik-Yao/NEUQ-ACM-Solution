#include<bits/stdc++.h>
using namespace std;
int a[100010],n,m,x,y,flag;
string s[100010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	flag=1;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		if(a[flag]==0){
			if(x==0)flag-=y;
			else flag+=y;
		}
		else{
			if(x==0)flag+=y;
			else flag-=y;
		}
		if(flag<=0)flag+=n;
		if(flag>=n+1)flag-=n;
	}
	cout<<s[flag];
}
