#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
int c,d;
int ans[10005];
int l=0;
void su(int x,int y)
{
	l=0;
	for(int i=x;i<=y;i++)
	{
		if(i==2)ans[++l]=i;
		else if(i==3)ans[++l]=i;
		else
		{
			int flag=0;
			for(int j=2;j<=sqrt(i)+1;j++)
			{
				if(i%j==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)ans[++l]=i;
		}
	}
	for(int i=1;i<l;i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<ans[l];
}
int a[1000005],b[1000005];
int len=0;
int main()
{
	while(cin>>c>>d)
	{
		a[++len]=c;
		b[++len]=d;
	}
	for(int i=1;i<=len;i+=2)
	{
		su(a[i],b[i+1]);
		if(i!=len-1)cout<<endl;
	}
	return 0;
}
