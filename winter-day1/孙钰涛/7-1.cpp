#include<iostream>
using namespace std;
long long a[1000001];
int lowbit(int x)
{
	return x&(-x);
}
long long sumsum(int x)
{
	long long sum=0;
	for(int i=x;i>0;i=i-lowbit(i))
		sum=sum+a[i];
		return sum;
}
int main()
{
	int num,sum=0,n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		for(int j=i;j<=n;j=j+lowbit(j))
			a[j]=a[j]+num;
	}
	for(int i=1;i<=q;i++)
	{
		int flag,k,b;
		cin>>flag>>k>>b;
		if(flag==1)
		{
			for(int j=k;j<=n;j=j+lowbit(j))
				a[j]=a[j]+b;
		}
		else if(flag==2)
		{
			cout<<sumsum(b)-sumsum(k-1)<<"\n";
		}
	}
	
	return 0;
}