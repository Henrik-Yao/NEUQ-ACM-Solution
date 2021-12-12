#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,p[51],ans;
	p[1]=1;
	p[2]=2;
	p[3]=4;
	for(int i=4;i<=50;i++)
	p[i] = p[i-1]+p[i-2]+p[i-3];
	while(cin>>n)
	ans=p[n],cout<<ans<<endl;
	return 0;
}
