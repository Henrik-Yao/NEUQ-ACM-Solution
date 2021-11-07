#include<bits/stdc++.h>
using namespace std;
long long int Q(long long a,long long b,long long c);
int main(){
	long long int t,a,b,c;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>a>>b>>c;
	    cout<<Q(a,b,c)<<endl;
	}
	
	
}
long long int Q(long long a,long long b,long long c)
{
	long long int ans = 1;
	while (b)
	{	if (b % 2 == 1)
		ans = (ans * a) % c;
		b /= 2;
		a = (a * a) % c;
	}
	return ans;
}
