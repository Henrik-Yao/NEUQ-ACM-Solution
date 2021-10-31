#include <iostream>
using namespace std;
typedef long long ll;
ll gui(int a[],int s,int e,int m);
ll bin(int a[],int s,int e,int m);
int main()
{
	ll n,sum;
	cin>>n;
	int a[n+1];
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sum=gui(a,1,n,(n+1)/2);
	cout<<sum;
}

ll gui(int a[],int s,int e,int m)
{
    ll sum=0;
    if(s==e)
	return 0;
	sum+=gui(a,s,m,(s+m)/2);
	sum+=gui(a,m+1,e,(m+1+e)/2);
	sum+=bin(a,s,e,m);
    return sum;
}

ll bin(int a[],int s,int e,int m)
{
    ll sum=0;
	int b[e-s+1];
	int i=s,j=m+1,l=0;
	while(i<=m&&j<=e)
	{
		if(a[i]>a[j])
        {
        sum+=m-i+1;
		b[l++]=a[j++];
        }
		else
		b[l++]=a[i++];
	}
	while(i<=m)
    {
    
	b[l++]=a[i++];
    }
	while(j<=e)
	b[l++]=a[j++];
	for(i=0;i<e-s+1;i++)
	a[s+i]=b[i];
    return sum;
}
