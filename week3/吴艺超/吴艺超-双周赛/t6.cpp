#include<bits/stdc++.h>
#include<vector>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x*f;
}
char c[100];
bool c1[100];
char a[10];
void qms(int m)
{
	if(m==strlen(a))
	{
		for(int i=0;i<m;i++)
		cout<<c[i];
		cout<<endl;
		return;
	}
	int s2=strlen(a);
	for(int i=0;i<s2;i++)
	{
		if(c1[i]==1)
		continue;
		c[m]=a[i];
		c1[i]=1;
		qms(m+1);
		c1[i]=0;
	}
}
int main()
{
	cin>>a;
	sort(a,a+strlen(a));
	qms(0);
	return 0;
}
