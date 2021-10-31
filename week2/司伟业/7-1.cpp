#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100
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

int n;
char aa[maxn][maxn];

void f(int num,int from,int to)
{
    int mid=6-from-to;
	if(num==1)
	{
		printf("%s->%s\n",aa[from],aa[to]);
		return;
	}
	f(num-1,from,mid);
	f(1,from,to);
	f(num-1,mid,to);
}

int main()
{
	n=read();
	for(int i=1;i<=3;i++) scanf("%s",aa[i]);
	f(n,1,3);
	return 0;
}
