#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,x[1005],pos=1;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			int t=0;
			while(t<m-1)
			{
				pos--;
				if(pos==0)pos=n;
				if(x[pos]==0)t++;
			}
			x[pos]=1;
			 cout<<pos<<" ";
		}
		if(i%2==1)
		{
			int t=0;
			while(t<k-1)
			{
				pos++;
				if(pos>n)pos=1;
				if(x[pos]==0)t++;
			}
			x[pos]=1;
			 cout<<pos<<" ";
		}
	}
	return 0;
}
