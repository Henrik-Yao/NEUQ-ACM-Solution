#include<bits/stdc++.h>
using namespace std;

int Next[1000005];
int ans=0;
string a,b,p,temp[1005];

void getnext();
int kmp(string x,string y);

int main()
{

	int j=0,k=0;
	int flag=0;

	getline(cin,a);

	int lena = a.size();
	for(int i=0;i<=lena;i++)
	{
		if(a[i]>='a' && a[i]<='z')
		{
			b += a[i];
			flag=1;
		}
		else if(a[i]>='A' && a[i]<='Z')
		{
			b += a[i]+('a'-'A');
			flag=1;
		}
		else
		{
			if(flag==0)
			{
				b=""; continue;
			}
			else
			{
				temp[j]=b; j++; b="";
				flag=0;
			}
		}
	}

	cin>>p;
	for(int i=0;i<p.size();i++)
	{
		if(p[i]>='A' && p[i]<='Z')
		{
			p[i] += ('a'-'A');
		}
	}

	getnext();

	for(int i=0;i<j;i++)
		ans += kmp(temp[i],p);

	cout<<ans;
}

void getnext()
{
	Next[0]=-1;
	int len=p.size();
	int k=-1,j=0;
	while(j<len)
	{
		if(k==-1||p[k]==p[j])
		{
			j++; k++;
			Next[j]=k;
		}
		else
			k=Next[k];
	}
	return;
}

int kmp(string x,string y)
{
	int i=0,j=0;
	int len1=x.size();
	int len2=y.size();

	while(i<len1)
	{
		if(j==-1||x[i]==y[j])
		{
			j++; i++;
		}
		else
			j=Next[j];

		if(j>=len2)
			return 1;
	}
	return 0;
}

