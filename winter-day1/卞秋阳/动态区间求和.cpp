#include<bits/stdc++.h> 
using namespace std;
#define lowbit(x) ((x)&-(x))
long long n,q,l,r,w,sum=0;
long long tree[1000000+10];
long long a[1000000+10];
void add(int x,int d)
{
	while(x<=n){
		tree[x]+=d;
		x+=lowbit(x);
	}
}
long long int sum1(int x)
{
	long long sum=0;
	while(x>0)
	{
		sum+=tree[x];
		x-=lowbit(x);
	}
	return sum;
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		add(i,a[i]);
	}
	for(int i=1;i<=q;i++)
	{
		cin>>w>>l>>r;
		if(w==1)
		{
		 add(l,r); 
		}
		if(w==2)
		{
			sum=sum1(r)-sum1(l-1); 
			cout<<sum<<endl;
		    sum=0;
		}
		
	}
	
}
