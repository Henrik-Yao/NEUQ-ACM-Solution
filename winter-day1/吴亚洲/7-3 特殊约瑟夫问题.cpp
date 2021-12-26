#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool a[1005];
int main()
{
	cin>>n>>m>>k;
	int cnt=n,t=1;
	while(cnt)
	{
		if((n-cnt)%2==0)
		{
			int i=1;
			while(i<m)
			{
				t--;
				if(t==0)
				t=n;
				if(!a[t])
				i++;
			}
			a[t]=true;
		}
		else
		{
			int i=1;
			while(i<k)
			{
				t++;
				if(t==n+1)
				t=1;
				if(!a[t])
				i++;
			}
			a[t]=true;
		}
		cout<<t<<" ";
		cnt--;
	}
}
