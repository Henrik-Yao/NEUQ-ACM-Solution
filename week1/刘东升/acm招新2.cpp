#include<bits/stdc++.h>
const int M=1e6+50;
int n,a[M];
int p[M],s[M],v[M];//定义判断串，正串，反串 
using namespace std;
int main()
{
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int i=1;i<=n;i++)//记录每一项的非重复数字数量，桶排序 
	{
		if(v[a[i]])
		{
			p[i]=p[i-1];
		}
		else
		{
			p[i]=p[i-1]+1;
			v[a[i]]=1;
		}
	}
	memset(v,0,1000001);//归零桶排序 
	for(int i=n;i>0;i--)//同正串 
		{
			if(v[a[i]])
			{
				s[i]=s[i+1];	
			}
			else
			{
				s[i]=s[i+1]+1;
				v[a[i]]=1;
			}
		}
		int ma=-99999;
		for(int i=1;i<n;i++)//开始错加，判断每一项的权 
		{
			int sum=p[i]+s[i+1];
			if(ma<sum){ma=sum;}
			else{}
		}
		
		cout<<ma;
		
		return 0;
}
