#include <iostream>
using namespace std;
int c[201],d[201];
void sort(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	sort(l,mid);sort(mid+1,r);
	int p=l,q=mid+1,w=0;
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
	for(int i=l;i<=r;i++) c[i]=d[i-l+1];
}
int main()
{
	int t,m,n,a[101],b[101],r;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>m;
		for(int j=1;j<=m;j++) 
		{
			cin>>a[j];
			c[j]=a[j];
		}
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>b[j];
			c[j+m]=b[j];
		}
		r=m+n;
		sort(1,r);
		for(int j=1;j<=m+n-1;j++)
		{
			cout<<c[j]<<" ";
		}
		cout<<c[m+n];
	}
	return 0;
}
