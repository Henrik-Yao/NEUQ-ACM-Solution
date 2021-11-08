#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100005
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

int n,aa,pd,pd1;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();pd=0;pd1=0;
		for(int i=2;i*i<=aa;i++)
		{
			if(aa%i==0)
			pd=1;
		}
		for(int i=2;i*i<=aa-2;i++)
		{
			if((aa-2)%i==0)
			pd1=1;
		}
		if(pd==0){
			puts("1");continue;
		}
		if(pd==1&&aa%2==0)
		{
			puts("2");continue;
		}
		if(pd1==0)
		{
			puts("2");continue;
		}
		puts("3");
	}
	return 0;
}

