#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	x=x*10+(ch^48),ch=getchar();
	return x*f;
} 
int t;
bool pan(int x)
{
	for(int i=2;i<=sqrt(double(x));i++)
	{
		if(x%i==0)
		return 0;
	}
	return 1;
}
signed main()
{
	t=read();
	while(t--)
	{
		int x;
		x=read();
		if(x%2==0)
		{
			printf("2\n");
			continue;
		}
		if(pan(x))
		{
			printf("1\n");
			continue;
		}
		int tot=0;
		if(pan(x-2))tot=2;
		else tot=3;
		cout<<tot<<endl;
	}
	return 0;
}
