#include<bits/stdc++.h>
using namespace std;
int n;
int mid[11],back[11];
void fun(int ll,int lr,int rl,int rr)
{
	if(ll>lr)
	return;
	cout<<back[lr]<<' ';
	int pos;
	int t=back[lr];
	for(int i=rr;i>=rl;i--)
	{
		if(mid[i]==t)
		{
			pos=i;
			break;
		}
	}
	fun(ll,pos+ll-rl-1,rl,pos-1);
	fun(pos+ll-rl,lr-1,pos+1,rr);
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>back[i];
	for(int i=0;i<n;i++)
		cin>>mid[i];
	fun(0,n-1,0,n-1);
	return 0;
}
