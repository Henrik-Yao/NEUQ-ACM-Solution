#include<bits/stdc++.h>
using namespace std;
bool g[10001]={};
bool pd(int x)
{
	if(x<2) return 0;
	for(int i=2;i<=x/i;i++)
	{
		if(x%i==0) return 0;
	}
	g[x]=1;
	return 1;
}
void f(int a,int b)
{
	int flag=0;
	for(int i=a;i<=b;i++)
	{
		if(flag==0&&pd(i)==1)
		{
			printf("%d",i);
			flag=1;
		}
		else if(g[i]==1) printf(" %d",i);
		else if(pd(i)==1) printf(" %d",i);
	}
	puts("");
}
int main()
{
	int a,b;
	while(~scanf("%d %d",&a,&b))
	{
		f(a,b);
	}
	return 0;
}
