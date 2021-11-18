#include <bits/stdc++.h>
using namespace std;
int judge(int t)
{
	int i,n,b=1;
	for(i=2; i<=sqrt(t); i++)
		if(t%i==0)
		{
			b=0;
			break;
		}
	return b;
}
int main()
{
	int n,t,i,k;
	cin>>n;
	while(n--)
	{
		cin>>t;
		if(judge(t)) k=1;
		else if(t%2==0 || judge(t-2)==1) k=2;
		else k=3;
		cout<<k<<endl;
	}
	return 0;
}
