#include <iostream>
using namespace std;
void f(int a[],int m,int n);
int main()
{
	int a[100000];
	int i,n;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	f(a,1,n);
	for(i=1;i<=n;i++) cout<<a[i]<<' ';
	return 0;
}

void f(int a[],int m,int n)
{
	int i,j,mid,k;
	int p[100000];
	if(n==m) return;
	mid=(m+n)/2;
	f(a,m,mid);
	f(a,mid+1,n);
    k=0;
    i=m;
    j=mid+1;
	while(i<=mid&&j<=n)
	{
		if(a[i]<=a[j]) p[k++]=a[i++];
		else p[k++]=a[j++];
	}
	while(i<=mid) p[k++]=a[i++];
	while(j<=n) p[k++]=a[j++];
	i=m;
	k=0;
	while (i<=n) a[i++]=p[k++];
}
