#include <bits/stdc++.h>
using namespace std;
long long ans(long long n)
{
	if(n==1)
	return 1;
    
	else
	{
		int i,sum;
		sum=0;
		for(i=1;i<n;i++)
		{
		if(n%i==0)
		sum+=ans(i);
	    }
	    return sum+1;
	}
	
}
int main()
{
	long long n;
	cin>>n;
	cout<<ans(n);
	return 0;
}
