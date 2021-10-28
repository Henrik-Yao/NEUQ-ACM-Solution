#include<iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int io[n],lr[m],ins[m];
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>io[i]>>s[i];
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&lr[i],&ins[i]);
	}
	int t=0;
	for(int i=0;i<m;i++)
	{
		if((!io[t]&&!lr[i])||(io[t]&&lr[i]))
		{
			t-=ins[i];
		}
		else
		{
			t+=ins[i];
		}
		while(t>n-1||t<0)
		{
			if(t>n-1)
			{
				t-=n;
			}
			else
			{
				t+=n;
			}
		}
	}
	cout<<s[t];
	return 0;
}
