#include <bits/stdc++.h>
using namespace std;
long long c[1000100]={0}, t;
int n, q;

void updata(int i, int k)
{
	while(i<=n)
	{
		c[i]+=k;
		i+=i&(-i);
	}
}
long long sum(int i)
{
	long long res=0;
	while(i>0)
	{
		res+=c[i];
		i-=i&(-i);
	}
	return res;
}
int main(void)
{
	int ch, l, r;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>t, updata(i, t);
	
	while(q--)
	{
		cin>>ch>>l>>r;
		if(ch==1)
			updata(l, r);
		else
			cout<<sum(r)-sum(l-1)<<endl;
	}
	
	return 0;
}