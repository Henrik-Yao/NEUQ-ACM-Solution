#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n,T,max=0;
	cin>>n>>T;
	int v,t,a;
	cin>>v>>t;
	if(t<=T)
	{
		max=v;
	}
	else
	{
		max=v-(t-T);
	}	
	n--;
	while(n--)
	{
		cin>>v>>t;
		if(t<=T)
		{
			a=v;
		}
		else
		{
			a=v-(t-T);
		}
		if(a>max)
		{
			max=a;
		}
	}
	printf("%d",max);
}
