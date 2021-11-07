#include <iostream>
using namespace std;
long long n,c[1000001],d[1000001],x=0;
void nixu(long long l,long long r)
{
	if(l==r) return;
	long long mid=(l+r)/2;
	nixu(l,mid);nixu(mid+1,r);
	long long p=l,q=mid+1,w=0;
	for(long long i=l;i<=mid;i++)
	{
		for(long long j=r;j>=mid+1;j--)
		{
			if(c[i]>c[j])
			{
				x=x+j-mid;
				break;
			}
		}
	}
	while(p<=mid&&q<=r)
	{
		if(c[p]>c[q])
		{
			d[++w]=c[q];
			q++;
		}
		else{
			d[++w]=c[p];
			p++;
		}
	}
	while(p<=mid)
	{
		d[++w]=c[p];
		p++;
	}
	while(q<=r)
	{
		d[++w]=c[q];
		q++;
	}
	for(long long i=l;i<=r;i++) c[i]=d[i-l+1];
}
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>c[i];
	nixu(1,n);
	cout<<x;
	return 0; 
}
