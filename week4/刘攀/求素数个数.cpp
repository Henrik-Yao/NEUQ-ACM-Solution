#include<bits/stdc++.h>
using namespace std;
int prime[10000001];
int sum=0;
int main(){
	int n;
	cin>>n;
	int m=sqrt(n);
	for(int i=2;i<=m;i++){
		if(!prime[i]){
			for(int j=i*i;j<=10000001;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=n;i++){
		if(!prime[i]) sum++;
	}
	cout<<sum;
}
