#include<bits/stdc++.h>
using namespace std;
int top,cnt=0,a[110],maxx,cun[110],flag,pan[110];
void shuru(){
	string s;
	getline(cin,s);
	int len=s.length();
	int sum=0;
	int fu=1;
	for(int i=0;i<len;i++){
		if(s[i]=='-')fu=-fu;
		else if(isdigit(s[i])){
			sum*=10;
			sum+=s[i]-'0';
		}
		else{
			a[++cnt]=sum*fu;
			sum=0;
			fu=1;
		}
	}
	a[++cnt]=sum;
}
void dfs(int ceng){
	if(a[top+1]==0&&a[top+2]==0){
		cun[ceng]+=a[top];
		pan[ceng]=1;
		top+=2;
	}
	else{
		if(a[top+1]!=0){
			top++;
			dfs(ceng+1);
		}
		else top++;
		if(a[top+1]!=0){
			top++;
			dfs(ceng+1);
		}
		else top++;
	}
}
int main(){
	shuru();
	top=1;
	dfs(0);
	maxx=-1e9;
	//for(int i=1;i<=cnt;i++)cout<<a[i]<<' ';
	for(int i=0;i<=100;i++){
		//cout<<cun[i]<<' ';
		if(cun[i]>=maxx&&pan[i]==1){
			maxx=cun[i];
			flag=i;
		}
	}
	cout<<flag;
	return 0;
}
