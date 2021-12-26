#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1000001;
ll a[maxn],b[maxn];
int n;
int lowbit(int i)
{
	return i&(-i);
}
void update(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i)) b[i]+=y;
}
ll sum(int x)
{
	ll sumn=0;
	for(int i=x;i>0;i-=lowbit(i)) sumn+=b[i];
	return sumn;
}
int main()
{
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];update(i,a[i]);
	}
	for(int i=0;i<q;i++)
	{
		int z,l,r;
		cin>>z>>l>>r;
		if(z==1)
		{
			update(l,r);
		}
		else cout<<sum(r)-sum(l-1)<<endl;
	}
	return 0;
}
