#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
const int p=131;
const int pp=36;
map<ll,bool>v;
map<ll,ll>co;
map<ll,ll>coo;
ll HASH(char x[])
{
	ll summ=0;
	ll cass=pow(pp,3);
	int len=strlen(x);
	int ave=len/4;
	int cha=len%4;
	for(int i=0;i<strlen(x);i++)
	{
		if(cha)
		{
			ll sum=0;
			int j;
			for(j=i;j<=i+ave;j++)
			{
				if(x[j]>='0'&&x[j]<='9')
				{
					sum+=(int)(x[j]-'0');
				}
				else if(x[j]>='a'&&x[j]<='z')
				{
					sum+=(int)(x[j]-'a'+10);
				}
				else if(x[j]>='A'&&x[j]<='Z')
				{
					sum+=(int)(x[j]-'A'+10);
				}
			}
			summ+=sum%pp*cass;
			cass/=pp;
			cha--;
			i=j-1;
		}
		else
		{
			ll sum=0;
			int j;
			for(j=i;j<=i+ave-1;j++)
			{
				if(x[j]>='0'&&x[j]<='9')
				{
					sum+=(int)(x[j]-'0');
				}
				else if(x[j]>='a'&&x[j]<='z')
				{
					sum+=(int)(x[j]-'a'+10);
				}
				else if(x[j]>='A'&&x[j]<='Z')
				{
					sum+=(int)(x[j]-'A'+10);
				}
			}
			summ+=sum%pp*cass;
			cass/=pp;
			i=j-1;
		}
	}
	return summ;
}
ll has(char x[])
{
	ll sum=0;
	ll cas=1;
	for(int i=0;i<strlen(x);i++)
	{
		sum+=cas*(int)x[i]%inf;
		sum%=inf;
		cas*=p;
	}
	return sum%inf;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char x;
		char a[10005],b[10005];
		cin>>x;
		cin>>a>>b;
		if(x=='R')
		{
			if(v[has(a)]==0)
			{
				v[has(a)]=1;
				co[has(a)]=has(b);
				coo[has(a)]=HASH(b);
				cout<<"Signed!";
			}
			else if(v[has(a)]==1)
			{
				cout<<"Repeated!";
			}
		}
		else
		{
			if(has(b)!=co[has(a)]&&HASH(b)==coo[has(a)])
			{
				cout<<"Attention!";
			}
			else if(has(b)==co[has(a)])
			{
				cout<<"Success!";
			}
			else if(v[has(a)]==0||has(b)!=co[has(a)])
			{
				cout<<"Failed!";
			}
		}
		if(i!=n)cout<<endl;
	}
	return 0;
}
