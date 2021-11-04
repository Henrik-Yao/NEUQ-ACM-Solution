#include<bits/stdc++.h>
using namespace std;
double F[65],ans[65];
int n;
const int maxn=10000000; 
int main()
{
	F[1]=1;
	for(int i=2;i<=64;i++){
	F[i]=2*F[i-1]+1;
	ans[i]=maxn;
}
	ans[1]=1;
	for(int i=2;i<=64;i++){
	for(int j=1;j<i;j++){
	    ans[i]=min(ans[i],2*ans[j]+F[i-j]);
	}
}
	while(cin>>n)
	{
		cout<<ans[n]<<endl;
	}
	return 0;
}
