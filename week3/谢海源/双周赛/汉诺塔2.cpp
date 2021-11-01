#include<bits/stdc++.h>
using namespace std;
#define ll long long
double a[65]={};//4柱汉诺塔
double f(int n)//3柱汉诺塔
{
	return pow(2,n)-1;
}
int main()
{
	int n;
	a[1]=1;
	a[2]=3; 
	for(int i=3;i<=64;i++)
	{
		for(int j=1;j<i;j++)//枚举顶上要用4柱子汉诺塔的数
		{
			if(j==1)
			{
				a[i]=2*a[j]+f(i-j);
			}
			else
			{
				a[i]=min(2*a[j]+f(i-j),a[i]);
			}
		}
	}
	while(cin>>n)
	{
		printf("%d\n",(int)a[n]);	
	}		
	return 0;	
}
