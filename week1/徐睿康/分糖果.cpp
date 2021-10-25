#include<bits/stdc++.h>
using namespace std;
int cnt=0,n;
void dfs(int x){
	cnt++;
	for(int i=1;i<x;i++){
		if(x%i==0)
		dfs(i);
	}
}
int main(){
	cin>>n;
	dfs(n);
	cout<<cnt;
}
