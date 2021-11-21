#include<bits/stdc++.h>
using namespace std;
bool pd(int x)//是否为质数
{
	if(x<2) return 0;
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0) return 0;
	}
	return 1;
}
int f(int n)
{
	if(pd(n)==1) return 1;
	else if(n%2==0) return 2;
	else if(pd(n-2)==1) return 2;
	return 3;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<f(n)<<endl;
	}
    return 0;
}