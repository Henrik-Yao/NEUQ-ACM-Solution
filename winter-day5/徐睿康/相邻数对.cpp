#include<bits/stdc++.h>
using namespace std;
int cnt=0,a[1010],n;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(abs(a[i]-a[j])==1)cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
