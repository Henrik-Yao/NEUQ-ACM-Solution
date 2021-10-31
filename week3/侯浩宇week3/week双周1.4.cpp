#include<bits/stdc++.h>
using namespace std;
long long a[65],b[65];
int main(){
	a[1]=b[1]=1;
	for(int i=1;i<=64;i++)
		a[i]=b[i]=2*b[i-1]+1;
	for(int i=1;i<=64;i++)
		for(int j=0;j<i;j++)
			a[i]=min(a[i],2*a[j]+b[i-j]);
	int n;
	while(cin>>n)
		cout<<a[n]<<endl;
	return 0;
}
