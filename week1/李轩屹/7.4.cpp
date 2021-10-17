#include<bits/stdc++.h>
using namespace std;
int f(int n)
{	
	if(n==1) return 1;
	else if(n==2) return 2;
	else
	{
		int sum=1;
		for(int i=1;i<n;i++)
		{
			if(n%i==0) sum+=f(i);
		}
		return sum;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<f(n);
	return 0;
}
