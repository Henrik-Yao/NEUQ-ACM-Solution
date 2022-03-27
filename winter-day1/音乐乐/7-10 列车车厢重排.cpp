#include<bits/stdc++.h>
using namespace std;
int a[100],b[100],c[100];
int n,i;
bool check(int t,int n)
{
	for(i=0;i<n;i++)
		b[i]=a[i];
	//cout<<"t"<<t<<"n"<<n;
	int cnt=t;
	for(i=0;i<n&&cnt;i++)
	{
		if(b[i]==0)
		{
			continue;
		}
		else
		{
			//cout<<"i"<<i<<endl;
			int min=b[i];
			//cout<<"min"<<min;
			b[i]=0;
			cnt--;
			
				for(int j=i+1;j<n;j++)
				{
					if(b[j]==0) 
					continue;
					if(b[j]<min)
					{
						//cout<<"b[j]"<<b[j]<<' ';
						min=b[j];
						b[j]=0;
					}
				}
			
		}
	}
	int flag=1;
	for(i=0;i<n;i++)
	{
		if(b[i])
		flag=0;
	}
	if((!cnt&&flag==1)||cnt)
	{
		//cout<<t<<"true";
		return true;
	}
	//cout<<t<<"false";
		return false;
}

int main()
{
	int n,i,ans;
	cin>>n;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int min=a[0],p=1;
	c[0]=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]<min)
		{
			c[p++]=a[i];
			min=a[i];
		}
	}
	for(i=0;i<p-1;i++)
	cout<<c[i]<<' ';
	cout<<c[p-1];
	cout<<endl;
	int l=1,r=n;
	while(l<=r)
	{
		//cout<<"left"<<l<<' '<<"right"<<r<<endl;
		int mid=(l+r)/2;
		if(check(mid,n))
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
	cout<<ans;
	return 0;
}
