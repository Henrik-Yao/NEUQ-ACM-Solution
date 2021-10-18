#include<bits/stdc++.h>
#include<cmath>
#define R register
#define N 999
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48),ch=getchar();
	}
	return x*f;

}
int n,tot;
char a[60000];
char b[30];
void cha()
{
	int len1=strlen(a);
	int len2=strlen(b);
	for(int i=0;i<len1;i++)
	{
		if(i+len2<=len1)
		{
			if(a[i]==b[0])
			{
				int k=i;int f=0;
				while(a[k]==b[f])
				{
					if(f==len2-1)
					{
						tot++;
						break;
					}
					k++,f++;
				}
			}
		}
	}
}
int main()
{
	 n=read();
	 cin>>a;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>b;
	 	tot=0;
	 	cha();
	 	cout<<tot;
	 	if(i!=n)cout<<endl;
	 }
	return 0;
}
