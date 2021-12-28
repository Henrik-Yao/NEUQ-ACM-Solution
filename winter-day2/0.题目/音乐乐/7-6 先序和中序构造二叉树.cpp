#include<bits/stdc++.h>
using namespace std;
int n;
int front[11],mid[11];
void fun(int ll,int lr,int rl,int rr)
{
	if(ll>lr)
	return;
	int pos;
	int t=front[ll];
	for(int i=rl;i<=rr;i++)
	{
		if(mid[i]==t)
		{
			pos=i;
			break;
		}
	}
	fun(ll+1,ll+pos-rl,rl,pos-1);
	fun(ll+pos-rl+1,lr,pos+1,rr);
	cout<<t<<' ';
}

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>front[i];
	for(int i=0;i<n;i++)
		cin>>mid[i];
	fun(0,n-1,0,n-1);
	return 0;
}
