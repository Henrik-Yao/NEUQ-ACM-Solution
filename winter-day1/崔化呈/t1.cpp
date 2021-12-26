#include<bits/stdc++.h>
using namespace std;
const int M=1e6+50;
typedef long long ll;
ll a[M];
int n,q;
int lowbit(int i)
{
	return (i&(-i));
}
void update(int x,int v)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		a[i]+=v;
	}
}
ll getsum(int x)
{
	ll sum=0;
	for(int i=x;i>0;i-=lowbit(i))
	{
		sum+=a[i];
	}
	return sum;
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++){int t;cin>>t;update(i,t);}
	for(int i=0;i<q;i++)
	{
		int c;
		cin>>c;
		if(c==1)
		{
			int w,x;
			cin>>w>>x;
			update(w,x);
		}
		else
		{
			ll sum=0;
			int l,r;
			cin>>l>>r;
			cout<<getsum(r)-getsum(l-1)<<endl;
		}
	} 
	return 0;
}
