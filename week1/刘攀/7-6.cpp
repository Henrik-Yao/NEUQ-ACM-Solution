#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	long long t;
	long long a,b;
	long long c[100000];
	cin>>n>>t;
	int maxn=0;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		if(b>t)
		a=a+t-b;
		c[i]=a;
	}
	sort(c,c+n);
	cout<<c[n-1];
}
