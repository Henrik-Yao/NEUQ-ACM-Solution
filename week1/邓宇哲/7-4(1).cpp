#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=1000;i++){
	for(int j=1;j<i;j++){
		if(i%j==0)
		dp[i]+=dp[j];
	}
	dp[i]++;
}
	cout<<dp[n];
}
