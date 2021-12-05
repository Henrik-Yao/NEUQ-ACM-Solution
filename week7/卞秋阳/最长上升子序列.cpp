#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[1100];
int dp[1100];
int m=0,n,i=1;int s;
int p,q;
int main(){
	cin>>p;
while(p--)
{
cin>>n; 
memset(a,0,sizeof(a));
while(n--){
	cin>>a[i];
	i++;
}
s=i;
	for(int k=1;k<=s;k++){
		dp[k]=1;
		for(int j=1;j<k;j++){
			if(a[k]>a[j])
			dp[k]=max(dp[k],dp[j]+1);
	
		}
	m=max(m,dp[k]);
		
		}
		
    cout<<m<<endl;
	if(p) cout<<endl;
	i=1;m=0;
}
}
