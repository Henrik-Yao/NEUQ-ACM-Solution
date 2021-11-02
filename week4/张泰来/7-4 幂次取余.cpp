#include <bits/stdc++.h>
using namespace std;
int T,B;
long long A,C;
long long pow(long long x,int y)
{
	long long sum = 1;
	for (;y;y >>= 1,x = x * x % C)
	{
		if (y & 1)
		{
			sum = sum * x % C;
		}
	}
	return sum; 
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%d%lld",&A,&B,&C);
		long long ans = pow(A % C,B);
		printf("%lld\n",ans);
	}
	
	return 0;
}
