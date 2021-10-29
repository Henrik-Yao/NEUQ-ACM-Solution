#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	int sum=0,ss=0;
	for(i=0;i<n;i++){
		if((sum+a[i])<0){
			ss=max(ss,sum);
			sum=0;
			continue;
		} sum+=a[i];
		ss=max(ss,sum);
	}
	cout<<ss<<endl;
	return 0;
}
