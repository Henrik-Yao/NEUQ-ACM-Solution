#include<bits/stdc++.h>
using namespace std;
long long dp[100];
int main(){
	dp[1]=0;
	dp[2]=1;
	dp[3]=2;
	int n;
	cin>>n;
	int m;
	for(int i=4;i<=40;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	while(n--){
		cin>>m;
		cout<<dp[m];
		if(n!=0)
		cout<<endl;
	}
}
